#include "cputemp.h"
#include "imodule.h"
#include <filesystem>
#include <fstream>

using namespace dsh;
namespace fs = std::filesystem;

CPUTemp::CPUTemp() : IModule(2000) {
    for (const auto& entry : fs::directory_iterator("/sys/class/hwmon")) {
        std::ifstream name_file(entry.path() / "name");
        if (name_file.is_open()) {
            std::string name;
            name_file >> name;

            if (name == "k10temp" || name == "coretemp") {
                hwmon_path = entry.path().string();
                break;
            }
        }
    }
}

void CPUTemp::update() {
    std::lock_guard<std::mutex> lock(this->property_mutex);

    if (!hwmon_path.empty()) {
        std::ifstream temp_file(hwmon_path + "/temp1_input");
        if (temp_file.is_open()) {
            int millidegrees = 0;
            temp_file >> millidegrees;
            this->current_temp = millidegrees / 1000;
        }
    } else {
        this->current_temp = -1;
    }
}

PropertyValue CPUTemp::get_property(std::string key) {
    std::lock_guard<std::mutex> lock(this->property_mutex);
    if (key == "temp") {
        return this->current_temp;
    }
    return 0;
}
