#include "Map.h"

#include "../engine/Window.h"

namespace blasted_city {

Map::Map()
  : height_(Window::instance()->height()),
    width_(Window::instance()->width())
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
