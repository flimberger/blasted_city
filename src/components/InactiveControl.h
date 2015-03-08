#pragma once

#include "IControlComponent.h"

namespace blasted_city {

class InactiveControl : public IControlComponent
{
public:
    InactiveControl();
    ~InactiveControl();

private:
    virtual void UpdateImpl(World &world, Entity &entity) override;
};

} // namespace blasted_city
