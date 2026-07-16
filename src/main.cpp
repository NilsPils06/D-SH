#include <ftxui/component/event.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/loop.hpp>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

using namespace ftxui;

std::string get_current_time() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_t = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_t);
    std::stringstream sstream;
    sstream << std::put_time(now_tm, "%H:%M:%S");

    return sstream.str();
}

int main() {
    auto screen = ScreenInteractive::Fullscreen();

    auto renderer = Renderer([&] {
        std::string current_time = get_current_time();
        return vbox({
            text("Druk op 'u' om de tijd bij te werken") | border,
            text("Huidige tijd: " + current_time) | color(Color::Green) | border,
            text("Druk op 'q' om te sluiten") | dim
        });
    });

    screen.Loop(renderer);

    return 0;
}
