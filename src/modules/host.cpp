#include "host.h"
#include "imodule.h"
#include <mutex>

using namespace dsh;

void HostInfo::update() {
    std::lock_guard<std::mutex> lock(property_mutex);
    uname(&uts);
}

PropertyValue HostInfo::get_property(std::string key) {
    std::lock_guard<std::mutex> lock(property_mutex);
    if (key == "sysname")
        return this->uts.sysname;
    if (key == "machine")
        return this->uts.machine;
    if (key == "release")
        return this->uts.release;
    if (key == "name")
        return this->uts.nodename;

    return 0;
}
