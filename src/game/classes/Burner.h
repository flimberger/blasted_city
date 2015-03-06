#ifndef BLASTED_CITY_GAME_CLASSES_BURNER_H_
#define BLASTED_CITY_GAME_CLASSES_BURNER_H_

#include "../Soldier.h"

namespace blasted_city {

class Burner : public Soldier
{
 public:
  Burner(GraphicsPtr graphics, InputPtr input, PhysicsPtr physics, Vec3 initialPose,
         uint16_t hitpoints);
  virtual ~Burner();

 private:
  virtual void AttackImpl() override;
  virtual void InteractImpl() override;
  virtual void SpecialActionImpl() override;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_CLASSES_BURNER_H_
