#ifndef DSH_CLOCK_UI_H
#define DSH_CLOCK_UI_H

#include "../modules/clock.h"
#include "iview.h"
#include <ftxui/dom/elements.hpp>
#include <memory>

using namespace ftxui;

namespace dsh {
class ClockUI : public IView {
public:
    ClockUI(std::shared_ptr<Clock> m) : IView(m) {};

    void render() override;
};
} // namespace dsh
#endif // DSH_CLOCK_UI_H
