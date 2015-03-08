#include "IGraphicsComponent.h"

namespace blasted_city {

IGraphicsComponent::~IGraphicsComponent() = default;

void IGraphicsComponent::Draw(const Entity &entity) const
{
    DrawImpl(entity);
}

} // namespace blasted_city
