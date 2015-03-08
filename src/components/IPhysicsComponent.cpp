#include "IPhysicsComponent.h"

namespace blasted_city {

IPhysicsComponent::~IPhysicsComponent() = default;

void IPhysicsComponent::Update(World &world, Entity &entity)
{
  UpdateImpl(world, entity);
}

} // namespace blasted_city
