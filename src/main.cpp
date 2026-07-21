#include "app.h"
#include "controller.h"
#include "modules/clock.h"
#include "modules/host.h"
#include "views/clock.h"
#include "views/host.h"
#include <memory>

int main() {
    dsh::Controller controller{};

    auto clock = std::make_shared<dsh::Clock>();
    auto clockUI = std::make_shared<dsh::ClockUI>(clock);

    auto host = std::make_shared<dsh::HostInfo>();
    auto hostUI = std::make_shared<dsh::HostInfoUI>(host);

    controller.register_module(clock);
    controller.register_view(clockUI);

    controller.register_module(host);
    controller.register_view(hostUI);

    dsh::App app(controller);
    app.run();

    return 0;
}
