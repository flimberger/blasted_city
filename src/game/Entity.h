#ifndef BLASTED_CITY_GAME_ENTITY_H_
#define BLASTED_CITY_GAME_ENTITY_H_

#include "../math.h"

#include "../components/GraphicsComponent.h"
#include "../components/InputComponent.h"
#include "../components/PhysicsComponent.h"

#include <memory>

namespace blasted_city {

using GraphicsPtr = std::unique_ptr<GraphicsComponent>;
using InputPtr    = std::unique_ptr<InputComponent>;
using PhysicsPtr  = std::unique_ptr<PhysicsComponent>;

class Entity
{
 public:
  Entity() = delete;
  virtual ~Entity();

  void Update();

  const Vec3 &pose() const;
  const Vec2 &size() const;
  const Vec2 &speed() const;

  void set_pose(Vec3 pose);
  void set_size(Vec2 size);
  void set_speed(Vec2 speed);

 protected:
  Entity(GraphicsPtr graphics, InputPtr input, PhysicsPtr physics, Vec2 size);

  virtual void UpdateImpl();

 private:
  Vec3 pose_; // xy := position, z := rotation
  Vec2 size_;
  Vec2 speed_; // x := linear, y := rotational

  GraphicsPtr  graphics_;
  InputPtr     input_;
  PhysicsPtr   physics_;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_ENTITY_H_
