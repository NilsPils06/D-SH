#ifndef DSH_CPUTEMP_H
#define DSH_CPUTEMP_H

#include "imodule.h"
#include <string>

namespace dsh {
class CPUTemp : public IModule {
private:
    int current_temp = -1;
    std::string hwmon_path = "";

public:
    CPUTemp();

    void update() override;
    PropertyValue get_property(std::string key) override;
};
} // namespace dsh

#endif // DSH_CPUTEMP_H
