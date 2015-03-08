#pragma once

#include "IPhysicsComponent.h"

namespace blasted_city {

class ProjectilePhysics : public IPhysicsComponent
{
public:
    ProjectilePhysics();
    ~ProjectilePhysics();

private:
    virtual void UpdateImpl(World &world, Entity &entity) override;
};

} // namespace blasted_city
