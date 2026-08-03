#ifndef DSH_CPUTEMP_UI_H
#define DSH_CPUTEMP_UI_H

#include "../modules/cputemp.h"
#include "iview.h"
#include <memory>

using namespace ftxui;

namespace dsh {
class CPUTempUI : public IView {
public:
    CPUTempUI(std::shared_ptr<CPUTemp> m) : IView(m) {};

    void render() override;
};
} // namespace dsh

#endif // DSH_CPUTEMP_UI_H
