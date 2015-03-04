#ifndef BLASTED_CITY_GAME_WORLD_H_
#define BLASTED_CITY_GAME_WORLD_H_

#include "Map.h"

#include <memory>
#include <vector>

namespace blasted_city {

class Entity;
using EntityPtr = std::unique_ptr<Entity>;

class World
{
 public:
  World();
  ~World();

  void AddEntity(EntityPtr entity);
  void Draw() const;

 private:
  std::vector<EntityPtr>  entities_;
  Map                     map_;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_WORLD_H_
