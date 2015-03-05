#ifndef BLASTED_CITY_GAME_WORLD_H_
#define BLASTED_CITY_GAME_WORLD_H_

#include <memory>
#include <vector>

namespace blasted_city {

class Entity;
using EntityPtr = std::unique_ptr<Entity>;

class Map;
using MapPtr = std::unique_ptr<Map>;

class World
{
 public:
  World(MapPtr map);
  ~World();

  void AddEntity(EntityPtr entity);
  void Draw() const;

  Map *GetMap() const;

 private:
  std::vector<EntityPtr>  entities_;
  MapPtr                  m_map;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_WORLD_H_
