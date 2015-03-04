#ifndef BLASTED_CITY_GAME_INVENTORY_H_
#define BLASTED_CITY_GAME_INVENTORY_H_

#include "../global.h"

#include <memory>
#include <array>

namespace blasted_city {

class Item;

using ItemPtr = std::shared_ptr<Item>;

class Inventory
{
 public:
  Inventory();
  ~Inventory();

  uint16_t item_count() const;
  uint16_t weight() const;

  bool AddItem(const ItemPtr &item);
  void RemoveItem(uint16_t index);

  static constexpr std::size_t kInventorySize  = 8;

 private:
  std::array<ItemPtr, kInventorySize>  store_;
  uint16_t                               item_count_;
  uint16_t                               weight_;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_INVENTORY_H_
