#include "PhysicsImplementation.h"

#include "../game/Entity.h"
#include "../game/Map.h"

namespace blasted_city {

PhysicsImplementation::PhysicsImplementation(Map *map)
  : IPhysicsComponent(),
    m_map(map)
{}

PhysicsImplementation::~PhysicsImplementation() = default;

void PhysicsImplementation::UpdateImpl(World &world, Entity &entity)
{
    (void) world;

  auto        pose = entity.GetPose();
  const auto &size = entity.GetSize();

  if (pose.x < 0.0f) {
    pose.x = 0.0f;
  }
  if (pose.y < 0.0f) {
    pose.y = 0.0f;
  }
  if (pose.x > m_map->width() - size.x) {
    pose.x = m_map->width() - size.x;
  }
  if (pose.y > m_map->height() - size.y) {
    pose.y = m_map->height() - size.y;
  }
  entity.SetPose(pose);
}

} // namespace blasted_city
