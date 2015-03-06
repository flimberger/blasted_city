#include "Entity.h"

#include <cstdio>

namespace blasted_city {

Entity::Entity(GraphicsPtr graphics, InputPtr input, PhysicsPtr physics, Vec3 pose, Vec2 size)
  : pose_(std::move(pose)),
    size_(std::move(size)),
    graphics_(std::move(graphics)),
    input_(std::move(input)),
    physics_(std::move(physics))
{}

Entity::~Entity() = default;

void Entity::Update()
{
  UpdateImpl();
}

const Vec3 &Entity::pose() const
{
  return pose_;
}

const Vec2 &Entity::size() const
{
  return size_;
}

const Vec2 &Entity::speed() const
{
  return speed_;
}

void Entity::set_pose(Vec3 pose)
{
  pose_ = std::move(pose);
}

void Entity::set_size(Vec2 size)
{
  size_ = std::move(size);
}

void Entity::set_speed(Vec2 speed)
{
  speed_ = std::move(speed);
}

void Entity::UpdateImpl()
{
  input_->Update(*this);
  physics_->Update(*this);
  graphics_->Draw(*this);

  std::fprintf(stderr, "Entity::UpdateImpl: new Pose: (%f, %f, %f)\n", pose_.x, pose_.y, pose_.z);
}

} // namespace blasted_city
