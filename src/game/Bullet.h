#pragma once

#include "Entity.h"

#include "../math.h"

namespace blasted_city {

class Bullet : public Entity
{
public:
    Bullet(GraphicsPtr graphics, ControlPtr input, PhysicsPtr physics, Vec3 GetPose);
    ~Bullet();
};

} // namespace blasted_city
