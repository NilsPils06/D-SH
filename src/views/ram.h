#ifndef DSH_RAMUSAGE_UI_H
#define DSH_RAMUSAGE_UI_H

#include "../modules/ram.h"
#include "iview.h"
#include <memory>

using namespace ftxui;

namespace dsh {
class RAMUsageUI : public IView {
public:
    RAMUsageUI(std::shared_ptr<RAMUsage> m) : IView(m) {};

    void render() override;
};
} // namespace dsh

#endif // DSH_RAMUSAGE_UI_H
