#include "ProjectilePhysics.h"

#include "../game/Entity.h"
#include "../game/Map.h"
#include "../game/World.h"

namespace blasted_city {

ProjectilePhysics::ProjectilePhysics()  = default;
ProjectilePhysics::~ProjectilePhysics() = default;

void ProjectilePhysics::UpdateImpl(World &world, Entity &entity)
{
    const auto *map  = world.GetMap();
    const auto &pose = entity.GetPose();

    if (pose.x <= 0.0 || pose.x >= map->width() || pose.y <= 0.0
        || pose.y >= map->height()) {
        // remove from world
        entity.Delete();
    }
}

} // namespace blasted_city
