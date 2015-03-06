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

static uint32_t g_key_map_table[] = {
  GLFW_KEY_W,     // kMoveForward
  GLFW_KEY_S,     // kMoveBackward
  GLFW_KEY_A,     // kMoveLeft
  GLFW_KEY_D,     // kMoveRight
  GLFW_KEY_Q,     // kTurnLeft
  GLFW_KEY_E,     // kTurnRight
  GLFW_KEY_SPACE, // kAttack
  GLFW_KEY_F,     // kInteract
  GLFW_KEY_R,     // kReload
  GLFW_KEY_C      // kSpecialAction
};

} // namespace

LocalInputImplementation::LocalInputImplementation() = default;
LocalInputImplementation::~LocalInputImplementation() = default;

void LocalInputImplementation::UpdateImpl(Entity &entity)
{
  auto       *keys  = Window::GetInstance().key_states();
  auto        pose  = entity.pose();
  const auto &speed = entity.speed();

  if (keys[g_key_map_table[kMoveForward]]) {
    pose.x += speed.x * std::cos(pose.z);
    pose.y += speed.x * std::sin(pose.z);
  }
  if (keys[g_key_map_table[kMoveBackward]]) {
    pose.x -= speed.x * std::cos(pose.z);
    pose.y -= speed.x * std::sin(pose.z);
  }
  if (keys[g_key_map_table[kMoveLeft]]) {
    pose.x -= speed.x * std::cos(pose.z + kPi2);
    pose.y -= speed.x * std::sin(pose.z + kPi2);
  }
  if (keys[g_key_map_table[kMoveRight]]) {
    pose.x += speed.x * std::cos(pose.z + kPi2);
    pose.y += speed.x * std::sin(pose.z + kPi2);
  }
  if (keys[g_key_map_table[kTurnLeft]]) {
    pose.z -= speed.y;
  }
  if (keys[g_key_map_table[kTurnRight]]) {
    pose.z += speed.y;
  }
  entity.set_pose(pose);
  if (keys[g_key_map_table[kAttack]]) {
    static_cast<Soldier &>(entity).Attack();
  }
  if (keys[g_key_map_table[kInteract]]) {
    static_cast<Soldier &>(entity).Interact();
  }
  if (keys[g_key_map_table[kReload]]) {
    static_cast<Soldier &>(entity).Reload();
  }
  if (keys[g_key_map_table[kSpecialAction]]) {
    static_cast<Soldier &>(entity).SpecialAction();
  }
}

} // namespace blasted_city
