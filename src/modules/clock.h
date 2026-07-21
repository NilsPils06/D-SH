#ifndef DSH_CLOCK_H
#define DSH_CLOCK_H

#include "imodule.h"
#include <atomic>
#include <ctime>
#include <mutex>
#include <string>
#include <thread>

namespace dsh {
class Clock : public IModule {
private:
    std::string formatted_time;

public:
    Clock() : IModule() {}

    void update() override;
    PropertyValue get_property(std::string key) override;
};
} // namespace dsh

#endif // DSH_CLOCK_H
