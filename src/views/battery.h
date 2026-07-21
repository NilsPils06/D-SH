#ifndef DSH_BATTERY_UI_H
#define DSH_BATTERY_UI_H

#include "../modules/battery.h"
#include "iview.h"
#include <ftxui/dom/elements.hpp>
#include <memory>

using namespace ftxui;

namespace dsh {
class BatteryUI : public IView {
public:
    BatteryUI(std::shared_ptr<Battery> m) : IView(m) {};

    void render() override;
};
} // namespace dsh
#endif // DSH_BATTERY_UI_H
