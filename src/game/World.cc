#include "World.h"

#include "Entity.h"
#include "Map.h"

namespace blasted_city {

World::World(MapPtr map)
  : m_map(std::move(map))
{}

World::~World() = default;

void World::AddEntity(EntityPtr entity)
{
  entities_.push_back(std::move(entity));
}

void World::Draw() const
{
  for (auto &soldier : entities_) {
    soldier->Update();
  }
}

Map *World::GetMap() const
{
    return m_map.get();
}

} // namespace blasted_city
