#include "controller.h"

using namespace dsh;

Controller::~Controller() {
    this->running = false;
    if (this->worker.joinable()) {
        this->worker.join();
    }
}

void Controller::register_module(std::shared_ptr<IModule> module) { this->modules.push_back(module); }

void Controller::register_view(std::shared_ptr<IView> view) { this->views.push_back(view); }

std::vector<ftxui::Element> Controller::get_views() const {
    std::vector<ftxui::Element> elements;

    for (auto& view : this->views) {
        elements.push_back(view->get_element());
    }

    return elements;
}

void Controller::start() {
    this->running = true;
    this->worker = std::thread(&Controller::run, this);
}

void Controller::stop() {
    this->running = false;
    if (this->worker.joinable()) {
        this->worker.join();
    }
}

void Controller::run() {
    while (running) {
        for (auto module : this->modules) {
            module->update();
        }

        for (auto view : this->views) {
            view->render();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
