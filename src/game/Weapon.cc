#include "Weapon.h"

namespace blasted_city {

Weapon::Weapon(uint16_t weight, WeaponType weapon_type)
  : Item(weight, ItemType::kWeapon),
    weapon_type_(weapon_type)
{}

Weapon::~Weapon() = default;

WeaponType Weapon::weapon_type() const
{
  return weapon_type_;
}

} // namespace blasted_city
