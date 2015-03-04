#include "Item.h"

namespace blasted_city {

Item::Item(uint16_t weight, ItemType type)
  : weight_(weight),
    item_type_(type)
{}

Item::~Item() = default;

uint16_t Item::weight() const
{
  return weight_;
}

ItemType   Item::item_type() const
{
  return item_type_;
}

} // namespace blasted_city
