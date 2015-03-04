#include "GraphicsComponent.h"

namespace blasted_city {

GraphicsComponent::~GraphicsComponent() = default;

void GraphicsComponent::Draw(const Entity &entity)
{
  DrawImpl(entity);
}

} // namespace blasted_city
