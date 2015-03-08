#ifndef BLASTED_CITY_GAME_CLASSES_SNIPER_H_
#define BLASTED_CITY_GAME_CLASSES_SNIPER_H_

#include "../Soldier.h"

namespace blasted_city {

class Sniper : public Soldier
{
 public:
  virtual ~Sniper();

 protected:
  explicit Sniper(GraphicsPtr graphics, InputPtr input, PhysicsPtr physics, Vec3 initialPose, uint16_t hitpoints);

 private:
  virtual void SpecialActionImpl(World &world) override;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_CLASSES_SNIPER_H_
