#ifndef BLASTED_CITY_GAME_WEAPON_H_
#define BLASTED_CITY_GAME_WEAPON_H_

#include "Item.h"

namespace blasted_city {

enum class WeaponType
{
  kHeavy,
  kMelee,
  kPistol,
  kRifle,
  kSpecial
};

class Weapon : public Item
{
 public:
  virtual ~Weapon();

  WeaponType weapon_type() const;

 protected:
  explicit Weapon(uint16_t weight, WeaponType weapon_type);

 private:
  const WeaponType  weapon_type_;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_WEAPON_H_
