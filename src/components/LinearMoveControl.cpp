#include "LinearMoveControl.h"

#include "../game/Entity.h"
#include "../game/Map.h"
#include "../game/World.h"

namespace blasted_city {

LinearMoveControl::LinearMoveControl()  = default;
LinearMoveControl::~LinearMoveControl() = default;

void LinearMoveControl::UpdateImpl(World &world, Entity &entity)
{
    (void) world;

    auto        pose  = entity.GetPose();
    const auto &speed = entity.GetSpeed();

    pose.x += speed.x * std::cos(pose.z);
    pose.y += speed.x * std::sin(pose.z);

    entity.SetPose(pose);
}

} // namespace blasted_city
