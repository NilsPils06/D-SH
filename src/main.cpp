#include "modules/clock.h"
#include "ui/clock.h"
#include <chrono>
#include <string>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>

using namespace ftxui;

int main() {
    dsh::Clock clock{};
    dsh::ClockUI clockUI{clock};

    auto screen = ScreenInteractive::Fullscreen();

    std::thread refresh([&screen]() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            screen.PostEvent(Event::Custom);
        }
    });

    refresh.detach();

    auto renderer = Renderer([&] {
        return vbox({
            text(" D-SH Dashboard ") | bold | color(Color::Blue) | border,
            separator(),
            clockUI.render(),
            separator(),
            text(" [q] Close app") | dim,
        }) | border;
    });

    auto component = CatchEvent(renderer, [&](Event event) {
        if (event == Event::Character('q')) {
            screen.Exit();
            return true;
        }

        return false;
    });

    screen.Loop(component);

    return 0;
}
