#ifndef BLASTED_CITY_GAME_ITEM_H_
#define BLASTED_CITY_GAME_ITEM_H_

#include "../global.h"

namespace blasted_city {

enum class ItemType
{
  kAmmunition,
  kClothes,
  kTool,
  kWeapon
};

class Item
{
 public:
  virtual ~Item();

  uint16_t weight() const;
  ItemType item_type() const;

 protected:
  explicit Item(uint16_t weight, ItemType type);

 private:
  uint16_t        weight_;
  const ItemType  item_type_;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_ITEM_H_
