#include "InputComponent.h"

namespace blasted_city {

InputComponent::~InputComponent() = default;

void InputComponent::Update(Entity &entity)
{
   return UpdateImpl(entity);
}

} // namespace blasted_city
