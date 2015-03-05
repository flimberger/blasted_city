#include "IPhysicsComponent.h"

namespace blasted_city {

IPhysicsComponent::~IPhysicsComponent() = default;

void IPhysicsComponent::Update(Entity &entity)
{
  UpdateImpl(entity);
}

} // namespace blasted_city
