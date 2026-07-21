#ifndef DSH_IMODULE_H
#define DSH_IMODULE_H

#include <mutex>
#include <shared_mutex>
#include <string>
#include <variant>

namespace dsh {
using PropertyValue = std::variant<std::string, int, double>;

class IModule {
protected:
    std::mutex property_mutex;
    int update_interval_ms;
    int time_since_update_ms;

public:
    IModule(int time_interval = 1000) : update_interval_ms(time_interval), time_since_update_ms(time_interval) {}

    virtual ~IModule() = default;

    virtual void update() = 0;
    virtual PropertyValue get_property(std::string key) = 0;

    void tick(int ms) {
        time_since_update_ms += ms;
        if (time_since_update_ms >= update_interval_ms) {
            update();
            time_since_update_ms = 0;
        }
    }
};
} // namespace dsh
#endif // DSH_IMODULE_H
