#include "battery.h"
#include <string>

using namespace dsh;
using namespace ftxui;

void BatteryUI::render() {
    std::lock_guard<std::mutex> lock(this->element_mtx);
    std::string status = this->get_string_property("status");
    int capacity = this->get_int_property("capacity");
    float capacity_gauge = capacity / 100.0f;

    // Uncomment if testing on desktop
    // capacity_gauge = 0.1;
    // status = "Charging";
    //
    std::string battery_text = (capacity != -1) ? std::to_string(capacity) + "%" : "";

    Color battery_color = Color::Yellow;
    if (status == "Charging") {
        battery_color = Color::Green;
    } else if (capacity < 0.25) {
        battery_color = Color::Red;
    }

    this->element = vbox({text("Battery") | bold | center, separator(),
                          hbox({
                              text(battery_text) | color(battery_color) | bold,
                              gauge(capacity_gauge) | color(battery_color),
                          }),
                          text(status) | dim | center}) |
                    border | size(WIDTH, GREATER_THAN, 25);
}
