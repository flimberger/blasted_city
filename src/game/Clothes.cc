#include "Clothes.h"

namespace blasted_city {

Clothes::Clothes(uint16_t weight)
  : Item(weight, ItemType::kClothes)
{}

Clothes::~Clothes() = default;

} // namespace blasted_city
