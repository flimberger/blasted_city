#ifndef BLASTED_CITY_GAME_CLASSES_BURNER_H_
#define BLASTED_CITY_GAME_CLASSES_BURNER_H_

#include "../Soldier.h"

namespace blasted_city {

class Burner : public Soldier
{
 public:
  Burner(GraphicsPtr graphics, ControlPtr input, PhysicsPtr physics, Vec3 initialPose,
         uint16_t hitpoints);
  virtual ~Burner();

 private:
  virtual void SpecialActionImpl(World &world) override;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_CLASSES_BURNER_H_
