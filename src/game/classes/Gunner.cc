#include "Gunner.h"

#include "Classes.h"

namespace blasted_city {

Gunner::Gunner(GraphicsPtr graphics, ControlPtr input, PhysicsPtr physics, Vec3 initialPose,
               uint16_t hitpoints)
  : Soldier(std::move(graphics), std::move(input), std::move(physics), std::move(initialPose),
            hitpoints)
{}

Gunner::~Gunner() = default;

void Gunner::SpecialActionImpl(World &world)
{
    (void) world;
}

} // namespace blasted_city
