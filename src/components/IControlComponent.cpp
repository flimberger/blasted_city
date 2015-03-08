#include "IControlComponent.h"

namespace blasted_city {

IControlComponent::~IControlComponent() = default;

void IControlComponent::Update(World &world, Entity &entity)
{
   return UpdateImpl(world, entity);
}

} // namespace blasted_city
