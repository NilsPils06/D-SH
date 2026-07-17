#ifndef DSH_CLOCK_UI_H
#define DSH_CLOCK_UI_H

#include <ftxui/dom/elements.hpp>
#include <memory>
#include "../modules/clock.h"
#include "iview.h"

using namespace ftxui;

namespace dsh {
    class ClockUI : public IView {
        public:
            ClockUI(std::shared_ptr<Clock> c) : IView(c) {};

            void render() override;
    };
} // namespace dsh
 #endif // DSH_CLOCK_UI_H
