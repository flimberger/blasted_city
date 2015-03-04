#ifndef BLASTED_CITY_COMPONENTS_PHYSICSIMPLEMENTATION_H_
#define BLASTED_CITY_COMPONENTS_PHYSICSIMPLEMENTATION_H_

#include "PhysicsComponent.h"

namespace blasted_city {

class PhysicsImplementation : public PhysicsComponent
{
public:
    PhysicsImplementation();
    ~PhysicsImplementation();

private:
 virtual void UpdateImpl(Entity &entity) override;
};

} // namespace blasted_city

#endif // BLASTED_CITY_COMPONENTS_PHYSICSIMPLEMENTATION_H_
