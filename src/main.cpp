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
#include <functional>
#include <map>
#include <memory>
#include <vector>

template <typename M, typename V>
void register_component(dsh::Controller& controller) {
    auto module = std::make_shared<M>();
    auto view = std::make_shared<V>(module);
    controller.register_module(module);
    controller.register_view(view);
}

int main() {
    dsh::Controller controller{};

    std::map<std::string, std::function<void(dsh::Controller&)>> module_options = {
        {"clock", [](dsh::Controller& c) { register_component<dsh::Clock, dsh::ClockUI>(c); }},
        {"host", [](dsh::Controller& c) { register_component<dsh::HostInfo, dsh::HostInfoUI>(c); }},
        {"uptime", [](dsh::Controller& c) { register_component<dsh::Uptime, dsh::UptimeUI>(c); }},
        {"battery", [](dsh::Controller& c) { register_component<dsh::Battery, dsh::BatteryUI>(c); }},
    };

    // TODO add a way to specify options/config

    // temporary solution for testing
    std::vector<std::string> options = {"clock", "host", "uptime", "battery"};
    for (auto& option : options) {
        if (module_options.find(option) != module_options.end()) {
            module_options[option](controller);
        }
    }

    dsh::App app(controller);
    app.run();

    return 0;
}
