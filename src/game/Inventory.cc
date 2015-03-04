#include "Inventory.h"

#include <cassert>

namespace blasted_city {

Inventory::Inventory()
  : item_count_(0),
    weight_(0)
{}

Inventory::~Inventory() = default;

uint16_t Inventory::item_count() const
{
  return item_count_;
}

uint16_t Inventory::weight() const
{
  return weight_;
}

bool Inventory::AddItem(const ItemPtr &item)
{
  if (item_count_ < kInventorySize) {
    store_[item_count_] = item;
    ++item_count_;

    return true;
  }
  return false;
}

void Inventory::RemoveItem(uint16_t index)
{
  assert(index < kInventorySize);
  store_[index] = nullptr;
}

} // namespace blasted_city
