#ifndef DSH_HOST_UI_H
#define DSH_HOST_UI_H

#include "../modules/host.h"
#include "iview.h"

using namespace ftxui;

namespace dsh {
class HostInfoUI : public IView {
public:
    HostInfoUI(std::shared_ptr<HostInfo> c) : IView(c) {};

    void render() override;
};
} // namespace dsh
#endif // DSH_HOST_UI_H
