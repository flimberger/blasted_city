#include "IGraphicsComponent.h"

namespace blasted_city {

IGraphicsComponent::~IGraphicsComponent() = default;

void IGraphicsComponent::Draw(const Entity &entity)
{
    DrawImpl(entity);
}

} // namespace blasted_city
