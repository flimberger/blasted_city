#include "World.h"

#include "Entity.h"

namespace blasted_city {

World::World()
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

} // namespace blasted_city
