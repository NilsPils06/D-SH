#include "clock.h"

using namespace dsh;
using namespace ftxui;

ClockUI::ClockUI(Clock& clock_ref) : clock(clock_ref) {}

Element ClockUI::render() {
    return hbox({
        text(" Current time: ") | color(Color::White),
        text(" " + clock.get_time() + " ") | color(Color::Green) | bold,
    });
}
