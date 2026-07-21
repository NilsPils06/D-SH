#ifndef DSH_HOST_H
#define DSH_HOST_H

#include "imodule.h"
#include <sys/utsname.h>

namespace dsh {
class HostInfo : public IModule {
private:
    utsname uts;

public:
    HostInfo() : IModule(86400) {}

    void update() override;
    PropertyValue get_property(std::string key) override;
};
} // namespace dsh

#endif // DSH_HOST_H
