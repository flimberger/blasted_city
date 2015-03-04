#include "SpriteGraphicsImplementation.h"

#include "../engine/Sprite.h"

#include "../game/Entity.h"

namespace blasted_city {

SpriteGraphicsImplementation::SpriteGraphicsImplementation(const SpritePtr &sprite)
  : sprite_(sprite)
{}

SpriteGraphicsImplementation::~SpriteGraphicsImplementation() = default;

void SpriteGraphicsImplementation::DrawImpl(const Entity &entity)
{
  const auto &pose = entity.pose();

  sprite_->Draw(Vec2(pose.x, pose.y), entity.size(), pose.z - kPi2);
}

} // namespace blasted_city
