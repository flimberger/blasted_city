#pragma once

#include "IControlComponent.h"

namespace blasted_city {

class Map;

class LinearMoveControl : public IControlComponent
{
public:
    LinearMoveControl();
    ~LinearMoveControl();

private:
    virtual void UpdateImpl(World &world, Entity &entity) override;
};

} // namespace blasted_city
