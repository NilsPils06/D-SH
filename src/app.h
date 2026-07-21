#ifndef DSH_APP_H
#define DSH_APP_H

#include "controller.h"
#include <ftxui/component/screen_interactive.hpp>
#include <memory>

namespace dsh {
class App {
private:
    Controller& controller;
    ftxui::ScreenInteractive screen;
    bool running = false;
    std::thread refresh;

public:
    App(Controller& ctrl);
    ~App();

    void run();
};
} // namespace dsh
#endif // DSH_APP_H
