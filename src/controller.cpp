#include "controller.h"

using namespace dsh;

Controller::Controller() : running(true) {
    this->worker = std::thread(&Controller::run, this);
}

Controller::~Controller() {
    running = false;
    if (this->worker.joinable()) {
        this->worker.join();
    }
}

void Controller::registerModule(std::shared_ptr<IModule> module) {
    this->modules.push_back(module);
}

void Controller::registerView(std::shared_ptr<IView> view) {
    this->views.push_back(view);
}

void Controller::stop() {
    this->running = false;
}

void Controller::run() {
    while (running) {
        for (auto module : this->modules) {
            module->update();
        }

        for (auto view : this->views) {
            view->render();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
