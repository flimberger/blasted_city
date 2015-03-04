#include "PhysicsImplementation.h"

#include "../engine/Window.h"

#include "../game/Entity.h"

namespace blasted_city {

PhysicsImplementation::PhysicsImplementation()  = default;
PhysicsImplementation::~PhysicsImplementation() = default;

void PhysicsImplementation::UpdateImpl(Entity &entity)
{
  auto       *win  = Window::instance();
  auto        pose = entity.pose();
  const auto &size = entity.size();

  if (pose.x < 0.0f) {
    pose.x = 0.0f;
  }
  if (pose.y < 0.0f) {
    pose.y = 0.0f;
  }
  if (pose.x > win->width() - size.x) {
    pose.x = win->width() - size.x;
  }
  if (pose.y > win->height() - size.y) {
    pose.y = win->height() - size.y;
  }
  entity.set_pose(pose);
}

} // namespace blasted_city
