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
  sprite_->Draw(Vec2(entity.pose_.x, entity.pose_.y), entity.size_, entity.pose_.z - kPi2);
}

} // namespace blasted_city
