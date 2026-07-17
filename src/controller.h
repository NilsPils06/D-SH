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
            bool running;

            void run();

        public:
            Controller();
            ~Controller();

            void registerModule(std::shared_ptr<IModule> module);
            void registerView(std::shared_ptr<IView> view);

            void stop();
    };
}

#endif // DSH_CONTROLLER_H
