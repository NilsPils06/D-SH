#include "clock.h"
#include <chrono>
#include <iomanip>
#include <mutex>
#include <sstream>

using namespace dsh;

void Clock::update() {
    auto now = std::chrono::system_clock::now();
    auto now_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_t), "%H:%M:%S");
    {
        std::lock_guard<std::mutex> lock(this->property_mutex);
        this->formatted_time = ss.str();
    }
}

std::string Clock::get_property(std::string key) {
    if (key == "time") {
        std::lock_guard<std::mutex> lock(this->property_mutex);
        return this->formatted_time;
    }

    return "";
}
