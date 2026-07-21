#ifndef DSH_BATTERY_H
#define DSH_BATTERY_H

#include "imodule.h"
#include <atomic>
#include <ctime>
#include <mutex>
#include <string>
#include <thread>

namespace dsh {
class Battery : public IModule {
private:
    int capacity;
    std::string status;

public:
    Battery() : IModule(5000) {}

    void update() override;
    PropertyValue get_property(std::string key) override;
};
} // namespace dsh

#endif // DSH_BATTERY_H
