#ifndef BLASTED_CITY_GAME_CLASSES_GUNNER_H_
#define BLASTED_CITY_GAME_CLASSES_GUNNER_H_

#include "../Soldier.h"

namespace blasted_city {

class Gunner : public Soldier
{
 public:
  virtual ~Gunner();

    Gunner(GraphicsPtr graphics, ControlPtr input, PhysicsPtr physics, Vec3 initialPose,
           uint16_t hitpoints);
 protected:

 private:
  virtual void SpecialActionImpl(World &world) override;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_CLASSES_GUNNER_H_
