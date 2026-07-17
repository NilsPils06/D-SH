#ifndef DSH_IVIEW_H
#define DSH_IVIEW_H

#include <ftxui/dom/elements.hpp>
#include <memory>
#include <mutex>
#include "../modules/imodule.h"

namespace dsh {
    class IView {
        protected:
            std::shared_ptr<IModule> module;
            std::shared_ptr<ftxui::Node> element = ftxui::text("Loading...");
            std::mutex element_mtx;

        public:
            IView(std::shared_ptr<IModule> m) : module(m) {};
            virtual ~IView() = default;
            // virtual ftxui::Element render() = 0;
            virtual void render() = 0;
            std::shared_ptr<ftxui::Node> get_element() {
                std::lock_guard<std::mutex> lock(this->element_mtx);
                return this->element;
            };
    };
} // namespace dsh
#endif // DSH_IVIEW_H
