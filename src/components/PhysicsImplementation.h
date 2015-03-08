#ifndef BLASTED_CITY_COMPONENTS_PHYSICSIMPLEMENTATION_H_
#define BLASTED_CITY_COMPONENTS_PHYSICSIMPLEMENTATION_H_

#include "IPhysicsComponent.h"

namespace blasted_city {

class Map;

class PhysicsImplementation : public IPhysicsComponent
{
public:
    PhysicsImplementation(Map *map);
    ~PhysicsImplementation();

private:
 virtual void UpdateImpl(World &world, Entity &entity) override;

    Map  *m_map;
};

} // namespace blasted_city

#endif // BLASTED_CITY_COMPONENTS_PHYSICSIMPLEMENTATION_H_
