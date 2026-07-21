#ifndef DSH_UPTIME_H
#define DSH_UPTIME_H

#include "imodule.h"

namespace dsh {
class Uptime : public IModule {
private:
    double uptime_seconds;
    std::string uptime_text;

public:
    Uptime() : IModule() {}

    void update() override;
    PropertyValue get_property(std::string key) override;
};
} // namespace dsh

#endif // DSH_UPTIME_H
