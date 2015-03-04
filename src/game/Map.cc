#include "Map.h"

namespace blasted_city {

Map::Map()
  : height_(0),
    width_(0)
{}

Map::~Map() = default;

std::size_t Map::height() const
{
  return height_;
}

std::size_t Map::width() const
{
  return width_;
}

} // namespace blasted_city
