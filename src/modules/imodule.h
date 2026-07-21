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

public:
    virtual ~IModule() = default;
    virtual void update() = 0;
    virtual PropertyValue get_property(std::string key) = 0;
};
} // namespace dsh
#endif // DSH_IMODULE_H
