#ifndef BLASTED_CITY_GAME_WORLD_H_
#define BLASTED_CITY_GAME_WORLD_H_

#include <memory>
#include <list>

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
  void Draw()   const;
  void Update();

  Map *GetMap() const;

 private:
  std::list<EntityPtr>  m_entities;
  MapPtr                m_map;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_WORLD_H_
