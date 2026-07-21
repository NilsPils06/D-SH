#ifndef DSH_CONTROLLER_H
#define DSH_CONTROLLER_H

#include "modules/imodule.h"
#include "views/iview.h"
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

            void registerModule(std::shared_ptr<IModule> module);
            void registerView(std::shared_ptr<IView> view);

            void start();
            void stop();
    };
} // namespace dsh

#endif // DSH_CONTROLLER_H
