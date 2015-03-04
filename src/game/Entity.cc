#include "Entity.h"

#include <cstdio>

namespace blasted_city {

Entity::Entity(GraphicsPtr graphics, InputPtr input, PhysicsPtr physics, Vec2 size)
  : size_(std::move(size)),
    graphics_(std::move(graphics)),
    input_(std::move(input)),
    physics_(std::move(physics))
{}

Entity::~Entity() = default;

void Entity::Update()
{
  UpdateImpl();
}

void Entity::UpdateImpl()
{
  input_->Update(*this);
  physics_->Update(*this);
  graphics_->Draw(*this);

  std::fprintf(stderr, "Entity::UpdateImpl: new Pose: (%f, %f, %f)\n", pose_.x, pose_.y, pose_.z);
}

} // namespace blasted_city
