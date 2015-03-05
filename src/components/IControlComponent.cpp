#include "IControlComponent.h"

namespace blasted_city {

IControlComponent::~IControlComponent() = default;

void IControlComponent::Update(Entity &entity)
{
   return UpdateImpl(entity);
}

} // namespace blasted_city
