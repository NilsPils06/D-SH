#include "clock.h"
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace dsh;

Clock::Clock() : running(true) {
    worker_thread = std::thread(&Clock::update_loop, this);
}

Clock::~Clock() {
    running = false;
    if (worker_thread.joinable()) {
        worker_thread.join();
    }
}

void Clock::update_loop() {
    while (running) {
        auto now = std::chrono::system_clock::now();
        auto now_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&now_t), "%H:%M:%S");
        std::string new_time = ss.str();

        {
            std::lock_guard<std::mutex> lock(time_mutex);
            formatted_time = new_time;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

std::string Clock::get_time() {
    std::lock_guard<std::mutex> lock(time_mutex);
    return formatted_time;
}
