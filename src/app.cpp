#include "app.h"
#include <chrono>
#include <ftxui/component/component.hpp>
#include <thread>

using namespace dsh;
using namespace ftxui;

App::App(Controller& ctrl) : controller(ctrl), screen(ScreenInteractive::Fullscreen()) {}

App::~App() {
    running = false;
    if (refresh.joinable()) {
        refresh.join();
    }
}

void App::run() {
    running = true;

    controller.start();

    this->refresh = std::thread([this]() {
        while (this->running) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            this->screen.PostEvent(Event::Custom);
        }
    });

    auto renderer = Renderer([&] {
        std::vector<Element> module_elements = controller.get_views();

        return vbox({
                   text(" D-SH Dashboard ") | bold | color(Color::Blue) | center,
                   separator(),
                   flexbox({std::move(module_elements)}) | flex,
                   separator(),
                   text(" [q] Close app") | dim,
               }) |
               border;
    });

    auto component = CatchEvent(renderer, [&](Event event) {
        if (event == Event::Character('q')) {
            this->controller.stop();
            this->screen.Exit();
            return true;
        }
        return false;
    });

    this->screen.Loop(component);
}
