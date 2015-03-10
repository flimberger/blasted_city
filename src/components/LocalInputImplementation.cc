#include "LocalInputImplementation.h"

#include "../engine/Window.h"

#include "../game/Soldier.h"

namespace blasted_city {

namespace {

enum Actions {
    // Movement
    kMoveForward = 0,
    kMoveBackward,
    kMoveLeft,
    kMoveRight,
    kTurnLeft,
    kTurnRight,
    // Actions
    kAttack,
    kInteract,
    kReload,
    kSpecialAction
};

static const uint32_t kKeyMapTable[] = {
    kKeyW,     // kMoveForward
    kKeyS,     // kMoveBackward
    kKeyA,     // kMoveLeft
    kKeyD,     // kMoveRight
    kKeyQ,     // kTurnLeft
    kKeyE,     // kTurnRight
    kKeySpace, // kAttack
    kKeyF,     // kInteract
    kKeyR,     // kReload
    kKeyC      // kSpecialAction
};

} // namespace

LocalInputImplementation::LocalInputImplementation()  = default;
LocalInputImplementation::~LocalInputImplementation() = default;

void LocalInputImplementation::UpdateImpl(World &world, Entity &entity)
{
  auto       *keys  = Window::GetInstance().GetKeyStates();
  auto        pose  = entity.GetPose();
  const auto &speed = entity.GetSpeed();

  if (std::get<kKeyPressed>(keys[kKeyMapTable[kMoveForward]])) {
    pose.x += speed.x * std::cos(pose.z);
    pose.y += speed.x * std::sin(pose.z);
  }
  if (std::get<kKeyPressed>(keys[kKeyMapTable[kMoveBackward]])) {
    pose.x -= speed.x * std::cos(pose.z);
    pose.y -= speed.x * std::sin(pose.z);
  }
  if (std::get<kKeyPressed>(keys[kKeyMapTable[kMoveLeft]])) {
    pose.x -= speed.x * std::cos(pose.z + kPi2);
    pose.y -= speed.x * std::sin(pose.z + kPi2);
  }
  if (std::get<kKeyPressed>(keys[kKeyMapTable[kMoveRight]])) {
    pose.x += speed.x * std::cos(pose.z + kPi2);
    pose.y += speed.x * std::sin(pose.z + kPi2);
  }
  if (std::get<kKeyPressed>(keys[kKeyMapTable[kTurnLeft]])) {
    pose.z -= speed.y;
  }
  if (std::get<kKeyPressed>(keys[kKeyMapTable[kTurnRight]])) {
    pose.z += speed.y;
  }
  entity.SetPose(pose);
  if (std::get<kKeyFlankDown>(keys[kKeyMapTable[kAttack]])) {
    static_cast<Soldier &>(entity).Attack(world);
  }
  if (std::get<kKeyFlankDown>(keys[kKeyMapTable[kInteract]])) {
    static_cast<Soldier &>(entity).Interact(world);
  }
  if (std::get<kKeyFlankDown>(keys[kKeyMapTable[kReload]])) {
    static_cast<Soldier &>(entity).Reload();
  }
  if (std::get<kKeyFlankDown>(keys[kKeyMapTable[kSpecialAction]])) {
    static_cast<Soldier &>(entity).SpecialAction(world);
  }
}

} // namespace blasted_city
