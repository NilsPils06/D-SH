#include "battery.h"
#include <filesystem>
#include <fstream>
#include <mutex>
#include <string>

namespace fs = std::filesystem;

using namespace dsh;

void Battery::update() {
    std::lock_guard<std::mutex> lock(this->property_mutex);
    fs::path battery_path = "/sys/class/power_supply/BAT0";

    if (!fs::exists(battery_path)) {
        this->capacity = -1;
        this->status = "No Battery / Desktop Mode";
        return;
    }

    this->capacity = 0;
    std::ifstream capacity_file(battery_path / "capacity");
    if (capacity_file.is_open()) {
        capacity_file >> this->capacity;
        capacity_file.close();
    }

    this->status = "Unknown";
    std::ifstream status_file(battery_path / "status");
    if (status_file.is_open()) {
        status_file >> this->status;
        status_file.close();
    }
}

PropertyValue Battery::get_property(std::string key) {
    std::lock_guard<std::mutex> lock(this->property_mutex);
    if (key == "capacity") {
        return this->capacity;
    }
    if (key == "status") {
        return this->status;
    }

    return 0;
}
