#include "app.h"
#include "controller.h"
#include "modules/battery.h"
#include "modules/clock.h"
#include "modules/host.h"
#include "modules/uptime.h"
#include "views/battery.h"
#include "views/clock.h"
#include "views/host.h"
#include "views/uptime.h"
#include <filesystem>
#include <fstream>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace fs = std::filesystem;

template <typename M, typename V>
void register_component(dsh::Controller& controller) {
    auto module = std::make_shared<M>();
    auto view = std::make_shared<V>(module);
    controller.register_module(module);
    controller.register_view(view);
}

fs::path get_config_path() {
    fs::path config_dir;

    const char* xdg_config_home = std::getenv("XDG_CONFIG_HOME");

    if (xdg_config_home != nullptr && std::string(xdg_config_home) != "") {
        config_dir = xdg_config_home;
    } else {
        const char* home_dir = std::getenv("HOME");
        if (home_dir != nullptr) {
            config_dir = fs::path(home_dir) / ".config";
        } else {
            config_dir = ".";
        }
    }

    return config_dir / "d-sh" / "config.ini";
}

std::vector<std::string> parse_config() {
    std::vector<std::string> active_modules;
    fs::path filepath = get_config_path();
    std::ifstream file(filepath);

    if (!file.is_open()) {
        fs::path config_dir = filepath.parent_path();

        std::error_code ec;
        fs::create_directories(config_dir, ec);

        if (!ec) {
            std::ofstream out_file(filepath);
            if (out_file.is_open()) {
                out_file << "[modules]\n";
                out_file << "clock=true\n";
                out_file << "battery=true\n";
                out_file << "uptime=false\n";
                out_file << "host=false\n";
                out_file.close();
            }
        }
        return {"clock", "battery"};
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#' || line[0] == '[')
            continue;

        size_t delimiter_pos = line.find('=');
        if (delimiter_pos != std::string::npos) {
            std::string key = line.substr(0, delimiter_pos);
            std::string value = line.substr(delimiter_pos + 1);

            if (value == "true") {
                active_modules.push_back(key);
            }
        }
    }

    return active_modules;
}

int main() {
    dsh::Controller controller{};

    std::map<std::string, std::function<void(dsh::Controller&)>> module_options = {
        {"clock", [](dsh::Controller& c) { register_component<dsh::Clock, dsh::ClockUI>(c); }},
        {"host", [](dsh::Controller& c) { register_component<dsh::HostInfo, dsh::HostInfoUI>(c); }},
        {"uptime", [](dsh::Controller& c) { register_component<dsh::Uptime, dsh::UptimeUI>(c); }},
        {"battery", [](dsh::Controller& c) { register_component<dsh::Battery, dsh::BatteryUI>(c); }},
    };

    std::vector<std::string> options = parse_config();
    for (auto& option : options) {
        if (module_options.find(option) != module_options.end()) {
            module_options[option](controller);
        }
    }

    dsh::App app(controller);
    app.run();

    return 0;
}
