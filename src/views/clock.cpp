#include "clock.h"
#include <mutex>

using namespace dsh;
using namespace ftxui;

void ClockUI::render() {
    std::lock_guard<std::mutex> lock(this->element_mtx);
    this->element =  hbox({
        text(" Current time: ") | color(Color::White),
        text(" " + this->module.get_property("time") + " ") | color(Color::Green) | bold,
    });
}
