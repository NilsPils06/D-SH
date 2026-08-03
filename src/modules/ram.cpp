#include "ram.h"
#include "imodule.h"
#include <fstream>
#include <string>

using namespace dsh;

void RAMUsage::update() {
    std::ifstream meminfo("/proc/meminfo");
    std::string key;
    long value;
    std::string unit;

    long total_kb = -1;
    long available_kb = -1;

    if (meminfo.is_open()) {
        while (meminfo >> key >> value >> unit) {
            if (key == "MemTotal:") {
                total_kb = value;
            } else if (key == "MemAvailable:") {
                available_kb = value;
            }

            if (total_kb != -1 && available_kb != -1) {
                break;
            }
        }
    }

    if (total_kb > 0) {
        long used_kb = total_kb - available_kb;
        usage = static_cast<float>(used_kb) / total_kb;
    }

    total_mb = static_cast<int>(total_kb / 1024.0);
    available_mb = static_cast<int>(available_kb / 1024.0);
}

PropertyValue RAMUsage::get_property(std::string key) {
    std::lock_guard<std::mutex> lock(this->property_mutex);
    if (key == "usage") {
        return usage;
    }
    if (key == "total") {
        return total_mb;
    }
    if (key == "available") {
        return available_mb;
    }

    return "";
}
