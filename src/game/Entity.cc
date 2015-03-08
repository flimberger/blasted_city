#include "Entity.h"

#include <cstdio>

namespace blasted_city {

Entity::Entity(GraphicsPtr graphics, ControlPtr control, PhysicsPtr physics, Vec3 pose, Vec2 size)
  : m_pose(std::move(pose)),
    m_size(std::move(size)),
    m_control(std::move(control)),
    m_graphics(std::move(graphics)),
    m_physics(std::move(physics))
{}

Entity::~Entity() = default;

void Entity::Draw() const
{
    m_graphics->Draw(*this);
}

void Entity::Update(World &world)
{
  UpdateImpl(world);
}

const Vec3 &Entity::GetPose() const
{
  return m_pose;
}

const Vec2 &Entity::GetSize() const
{
  return m_size;
}

const Vec2 &Entity::GetSpeed() const
{
  return m_speed;
}

const ControlPtr &Entity::GetControlComponent() const
{
    return m_control;
}

const GraphicsPtr &Entity::GetGraphicsComponent() const
{
    return m_graphics;
}

const PhysicsPtr &Entity::GetPhysicsComponent() const
{
    return m_physics;
}

void Entity::SetPose(Vec3 pose)
{
  m_pose = std::move(pose);
}

void Entity::SetSize(Vec2 size)
{
  m_size = std::move(size);
}

void Entity::SetSpeed(Vec2 speed)
{
  m_speed = std::move(speed);
}

void Entity::UpdateImpl(World &world)
{
  m_control->Update(world, *this);
  m_physics->Update(world, *this);

  std::fprintf(stderr, "Entity::UpdateImpl: new Pose: (%f, %f, %f)\n", m_pose.x, m_pose.y, m_pose.z);
}

} // namespace blasted_city
