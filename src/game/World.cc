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
  m_entities.push_back(std::move(entity));
}

void World::Draw() const
{
    for (auto &entity : m_entities) {
        entity->Draw();
    }
}

void World::Update()
{
    for (auto &entity : m_entities) {
        entity->Update(*this);
        if (entity->ShouldDelete()) {
            m_entities.remove(entity);
        }
    }
}

Map *World::GetMap() const
{
    return m_map.get();
}

} // namespace blasted_city
