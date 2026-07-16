#ifndef DSH_CLOCK_UI_H
#define DSH_CLOCK_UI_H

#include <ftxui/dom/elements.hpp>
#include "../modules/clock.h"

using namespace ftxui;

namespace dsh {
    class ClockUI {
        private:
            Clock& clock;

        public:
            ClockUI(Clock& clock_ref);

            Element render();
    };
} // namespace dsh
 #endif // DSH_CLOCK_UI_H
