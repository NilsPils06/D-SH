#ifndef DSH_CONTROLLER_H
#define DSH_CONTROLLER_H

#include "modules/imodule.h"
#include "views/iview.h"
#include <ftxui/dom/elements.hpp>
#include <memory>
#include <thread>
#include <vector>

namespace dsh {
class Controller {
private:
    std::vector<std::shared_ptr<IModule>> modules;
    std::vector<std::shared_ptr<IView>> views;
    std::thread worker;
    bool running = false;

    void run();

public:
    Controller() = default;
    ~Controller();

    void register_module(std::shared_ptr<IModule> module);
    void register_view(std::shared_ptr<IView> view);

    std::vector<ftxui::Element> get_views() const;

    void start();
    void stop();
};
} // namespace dsh

#endif // DSH_CONTROLLER_H
