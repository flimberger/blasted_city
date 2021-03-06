#include "SpriteGraphicsImplementation.h"

#include "../engine/Sprite.h"

#include "../game/Entity.h"

namespace blasted_city {

SpriteGraphicsImplementation::SpriteGraphicsImplementation(const SpritePtr &sprite)
  : IGraphicsComponent(),
    sprite_(sprite)
{}

SpriteGraphicsImplementation::~SpriteGraphicsImplementation() = default;

void SpriteGraphicsImplementation::DrawImpl(const Entity &entity) const
{
  const auto &pose = entity.GetPose();

  sprite_->Draw(Vec2(pose.x, pose.y), entity.GetSize(), pose.z - kPi2);
}

} // namespace blasted_city
