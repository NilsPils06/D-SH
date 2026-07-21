#include "host.h"
#include <ftxui/dom/deprecated.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>

using namespace dsh;
using namespace ftxui;

void HostInfoUI::render() {
    std::lock_guard<std::mutex> lock(this->element_mtx);
    std::string name = get_string_property("name");
    std::string system = get_string_property("sysname") + " " + get_string_property("machine");
    std::string release = get_string_property("release");

    this->element = vbox({text("Host Info (" + name + ")") | bold | center, separator(),
                          hbox({text("System: "), text(system) | color(Color::Green), separator(), text("Release: "),
                                text(release) | color(Color::Green)})}) |
                    border | size(WIDTH, GREATER_THAN, 20);
}
