#include "Soldier.h"

#include "World.h"

#include "../engine/Sprite.h"

namespace blasted_city {

// this sucks, but so does C++... or at least glm
constexpr float kSoldierSize = 48.0f;

Rank GetNextRank(Rank rank)
{
  Rank next;

  switch (rank) {
  case kRecruit:
    next = kPrivate;
    break;
  case kPrivate:
    next = kSergeant;
    break;
  case kSergeant:
    next = kCaptain;
    break;
  case kCaptain:
    next = kLieutenant;
    break;
  case kLieutenant:
    next = kMajor;
    break;
  case kMajor:
  case kGeneral:
    next = kGeneral;
    break;
  }

  return next;
}

Soldier::Soldier(GraphicsPtr graphics, InputPtr input, PhysicsPtr physics, Vec3 initialPose,
                 uint16_t hitpoints)
  : Entity(std::move(graphics), std::move(input), std::move(physics), std::move(initialPose),
           Vec2(kSoldierSize, kSoldierSize)),
    hitpoints_(hitpoints),
    kill_count_(0),
    rank_(kRecruit)
{
  set_speed(Vec2(2.0, 0.05));
}

Soldier::~Soldier() = default;

void Soldier::Attack(World &world)
{
    (void) world;
}

void Soldier::Interact(World &world)
{
    (void) world;
}

void Soldier::Reload()
{
  // primary_weapon_.Reload();
}

void Soldier::SpecialAction(World &world)
{
  SpecialActionImpl(world);
}

uint16_t Soldier::hitpoints() const
{
  return hitpoints_;
}

uint16_t Soldier::kill_count() const
{
  return kill_count_;
}

Rank Soldier::rank() const
{
  return rank_;
}

void Soldier::AddKills(uint16_t count)
{
  kill_count_ += count;
  if (kill_count_ >= rank_ && rank_ < kGeneral) {
    rank_ = GetNextRank(rank_);
  }
}

void Soldier::DropItem(uint16_t inventory_index)
{
  inventory_.RemoveItem(inventory_index);
}

bool Soldier::TakeItem(const ItemPtr &item)
{
  return inventory_.AddItem(item);
}

void Soldier::UpdateImpl(World &world)
{
  Entity::UpdateImpl(world);
}

} // namespace blasted_city
