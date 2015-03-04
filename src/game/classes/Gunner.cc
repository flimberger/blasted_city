#include "Gunner.h"

#include "Classes.h"

namespace blasted_city {

Gunner::Gunner(GraphicsPtr graphics, InputPtr input, PhysicsPtr physics, uint16_t hitpoints)
  : Soldier(std::move(graphics), std::move(input), std::move(physics), hitpoints)
{}

Gunner::~Gunner() = default;

void Gunner::AttackImpl()
{}

void Gunner::InteractImpl()
{}

void Gunner::SpecialActionImpl()
{}

} // namespace blasted_city
