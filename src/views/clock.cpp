#include "clock.h"

using namespace dsh;
using namespace ftxui;

void ClockUI::render() {
    std::lock_guard<std::mutex> lock(this->element_mtx);
    std::string time_text = get_string_property("time");

    this->element = vbox({text("Clock") | bold | center, separator(),
                          hbox({
                              text("Time: "),
                              text(time_text) | color(Color::Green),
                          })}) |
                    border | size(WIDTH, GREATER_THAN, 20);
}
