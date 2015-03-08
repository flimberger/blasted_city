#include "Bullet.h"

#include <cstdio>

namespace blasted_city {

Bullet::Bullet(GraphicsPtr graphics, ControlPtr input, PhysicsPtr physics, Vec3 pose)
  : Entity(std::move(graphics), std::move(input), std::move(physics), std::move(pose),
           Vec2(4.0f, 2.0f))
{
    Entity::SetSpeed(Vec2(3.0, 0.0));

    std::fprintf(stderr, "Bullet::Bullet\n");
}

Bullet::~Bullet()
{
    std::fprintf(stderr, "Bullet::~Bullet\n");
}

} // namespace blasted_city
