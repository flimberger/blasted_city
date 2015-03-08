#include "Sniper.h"

#include "Classes.h"

namespace blasted_city {

Sniper::Sniper(GraphicsPtr graphics, ControlPtr input, PhysicsPtr physics, Vec3 initialPose,
               uint16_t hitpoints)
  : Soldier(std::move(graphics), std::move(input), std::move(physics), std::move(initialPose),
            hitpoints)
{}

Sniper::~Sniper() = default;

void Sniper::SpecialActionImpl(World &world)
{
    (void) world;
}

} // namespace blasted_city
