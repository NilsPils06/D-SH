#ifndef DSH_UPTIME_UI_H
#define DSH_UPTIME_UI_H

#include "../modules/uptime.h"
#include "iview.h"

using namespace ftxui;

namespace dsh {
class UptimeUI : public IView {
public:
    UptimeUI(std::shared_ptr<Uptime> m) : IView(m) {};

    void render() override;
};
} // namespace dsh
#endif // DSH_UPTIME_UI_H
