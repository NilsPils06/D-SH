#include "uptime.h"

using namespace dsh;
using namespace ftxui;

void UptimeUI::render() {
    std::lock_guard<std::mutex> lock(this->element_mtx);
    std::string uptime_text = get_string_property("uptime");

    this->element = vbox({text("Uptime") | bold | center, separator(),
                          hbox({
                              text(uptime_text) | color(Color::Green),
                          })}) |
                    border | size(WIDTH, GREATER_THAN, 20);
}
