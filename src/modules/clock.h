#ifndef DSH_CLOCK_H
#define DSH_CLOCK_H

#include <atomic>
#include <ctime>
#include <mutex>
#include <string>
#include <thread>

namespace dsh {
    class Clock {
        private:
            std::string formatted_time;
            std::mutex time_mutex;
            std::thread worker_thread;
            std::atomic<bool> running;

            void update_loop();

        public:
            Clock();
            ~Clock();

            std::string get_time();
    };
} // namespace dsh

#endif // DSH_CLOCK_H
