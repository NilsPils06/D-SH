#include "clock.h"
#include <chrono>
#include <mutex>

using namespace dsh;

void Clock::update() {
    auto now = std::chrono::system_clock::now();
    auto now_t = std::chrono::system_clock::to_time_t(now);

    char buffer[10];
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S", std::localtime(&now_t));
    {
        std::lock_guard<std::mutex> lock(this->property_mutex);
        this->formatted_time = buffer;
    }
}

PropertyValue Clock::get_property(std::string key) {
    if (key == "time") {
        std::lock_guard<std::mutex> lock(this->property_mutex);
        return this->formatted_time;
    }

    return 0;
}
