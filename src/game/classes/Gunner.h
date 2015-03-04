#ifndef BLASTED_CITY_GAME_CLASSES_GUNNER_H_
#define BLASTED_CITY_GAME_CLASSES_GUNNER_H_

#include "../Soldier.h"

namespace blasted_city {

class Gunner : public Soldier
{
 public:
  virtual ~Gunner();

 protected:
  Gunner(GraphicsPtr graphics, InputPtr input, PhysicsPtr physics, uint16_t hitpoints);

 private:
  virtual void AttackImpl() override;
  virtual void InteractImpl() override;
  virtual void SpecialActionImpl() override;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_CLASSES_GUNNER_H_
