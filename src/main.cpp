#include "app.h"
#include "controller.h"
#include "modules/clock.h"
#include "views/clock.h"
#include <memory>

int main() {
    dsh::Controller controller{};

    auto clock = std::make_shared<dsh::Clock>();
    auto clockUI = std::make_shared<dsh::ClockUI>(clock);

    controller.register_module(clock);
    controller.register_view(clockUI);

    dsh::App app(controller);
    app.run();

    return 0;
}
