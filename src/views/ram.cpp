#include "ram.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>
#include <string>

using namespace dsh;
using namespace ftxui;

void RAMUsageUI::render() {
    std::lock_guard<std::mutex> lock(this->element_mtx);
    float usage = this->get_float_property("usage");
    int total = this->get_int_property("total");
    int available = this->get_int_property("available");

    std::string usage_text =
        (total != -1) ? std::to_string(available) + "Mb / " + std::to_string(total) + "Mb Available" : "Error...";

    Color usage_color = Color::Yellow;
    if (usage < 0.25) {
        usage_color = Color::Green;
    } else if (usage > 0.8) {
        usage_color = Color::Red;
    }

    this->element = vbox({text("RAM Usage") | bold | center, separator(),
                          vbox({
                              text(usage_text) | color(usage_color) | bold,
                              gauge(usage) | color(usage_color),
                          })}) |
                    border | size(WIDTH, GREATER_THAN, 25);
}
