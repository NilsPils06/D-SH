#include "cputemp.h"

using namespace dsh;

void CPUTempUI::render() {
    std::lock_guard<std::mutex> lock(this->element_mtx);
    int temp = this->get_int_property("temp");

    std::string temp_text = (temp != -1) ? std::to_string(temp) + "°C" : "No temperature found...";

    Color temp_color = Color::Green;
    if (temp < 50) {
        temp_color = Color::Blue;
    } else if (temp < 0 || temp > 80) {
        temp_color = Color::Red;
    }

    this->element = vbox({text("Battery") | bold | center, separator(),
                          hbox({
                              text(temp_text) | color(temp_color) | bold,
                          })}) |
                    border | size(WIDTH, GREATER_THAN, 25);
}
