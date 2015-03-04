#include "PhysicsComponent.h"

namespace blasted_city {

PhysicsComponent::~PhysicsComponent() = default;

void PhysicsComponent::Update(Entity &entity)
{
  UpdateImpl(entity);
}

} // namespace blasted_city
