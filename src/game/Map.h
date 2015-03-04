#ifndef BLASTED_CITY_GAME_MAP_H_
#define BLASTED_CITY_GAME_MAP_H_

#include <vector>

namespace blasted_city {

class Tile
{
 public:
  Tile() = default;
  ~Tile() = default;
};

class Map
{
 public:
  Map();
  ~Map();

  std::size_t height() const;
  std::size_t width() const;

 private:
  std::vector<Tile>  tiles_;
  std::size_t        height_;
  std::size_t        width_;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_MAP_H_
