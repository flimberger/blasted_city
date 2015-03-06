#include "Burner.h"

#include "Classes.h"

namespace blasted_city {

Burner::Burner(GraphicsPtr graphics, InputPtr input, PhysicsPtr physics, Vec3 initialPose, uint16_t hitpoints)
  : Soldier(std::move(graphics), std::move(input), std::move(physics), std::move(initialPose),
            hitpoints)
{}

Burner::~Burner() = default;

void Burner::AttackImpl()
{}

void Burner::InteractImpl()
{}

void Burner::SpecialActionImpl()
{}

} // namespace blasted_city
