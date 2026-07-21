#include "uptime.h"
#include "imodule.h"
#include <fstream>
#include <mutex>
#include <string>

using namespace dsh;

void Uptime::update() {
    std::lock_guard<std::mutex> lock(property_mutex);
    this->uptime_seconds = -1;

    std::ifstream uptime_file("/proc/uptime");
    if (!uptime_file.is_open()) {
        this->uptime_text = "Error reading uptime file";
        return;
    }
    uptime_file >> this->uptime_seconds;
    uptime_file.close();

    if (uptime_seconds == -1) {
        this->uptime_text = "Error reading uptime";
        return;
    }

    int hours = this->uptime_seconds / 3600;
    int minutes = (int)this->uptime_seconds % 3600;
    minutes /= 60;
    int seconds = (int)this->uptime_seconds % 60;

    this->uptime_text = std::to_string(hours) + " Hours, " + std::to_string(minutes) + " Minutes, " +
                        std::to_string(seconds) + " Seconds";
}

PropertyValue Uptime::get_property(std::string key) {
    std::lock_guard<std::mutex> lock(property_mutex);
    if (key == "uptime")
        return uptime_text;

    return 0;
}
