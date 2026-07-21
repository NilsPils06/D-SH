#include "clock.h"

using namespace dsh;
using namespace ftxui;

void ClockUI::render() {
    std::lock_guard<std::mutex> lock(this->element_mtx);
    std::string time_text = get_string_property("time");

    this->element = hbox({
        text(" Current time: ") | color(Color::White),
        text(time_text) | color(Color::Green) | bold,
    });
}
