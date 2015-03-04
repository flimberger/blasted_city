#ifndef BLASTED_CITY_GAME_CLOTHES_H_
#define BLASTED_CITY_GAME_CLOTHES_H_

#include "Item.h"

namespace blasted_city {

class Clothes : public Item
{
 public:
  virtual ~Clothes();

 protected:
  explicit Clothes(uint16_t weight);
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_CLOTHES_H_
