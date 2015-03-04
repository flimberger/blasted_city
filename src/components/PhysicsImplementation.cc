#include "PhysicsImplementation.h"

#include "../engine/Window.h"

#include "../game/Entity.h"

namespace blasted_city {

PhysicsImplementation::PhysicsImplementation()  = default;
PhysicsImplementation::~PhysicsImplementation() = default;

void PhysicsImplementation::UpdateImpl(Entity &entity)
{
  auto *win = Window::instance();

  if (entity.pose_.x < 0.0f) {
    entity.pose_.x = 0.0f;
  }
  if (entity.pose_.y < 0.0f) {
    entity.pose_.y = 0.0f;
  }
  if (entity.pose_.x > win->width() - entity.size_.x) {
    entity.pose_.x = win->width() - entity.size_.x;
  }
  if (entity.pose_.y > win->height() - entity.size_.y) {
    entity.pose_.y = win->height() - entity.size_.y;
  }
}

} // namespace blasted_city
