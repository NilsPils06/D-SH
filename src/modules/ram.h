#ifndef DSH_RAMUSAGE_H
#define DSH_RAMUSAGE_H

#include "imodule.h"

namespace dsh {
class RAMUsage : public IModule {
private:
    float usage;
    int available_mb;
    int total_mb;

public:
    RAMUsage() : IModule() {}

    void update() override;
    PropertyValue get_property(std::string key) override;
};
} // namespace dsh

#endif // DSH_RAMUSAGE_H
