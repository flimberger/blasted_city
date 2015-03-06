#ifndef BLASTED_CITY_GAME_SOLDIER_H_
#define BLASTED_CITY_GAME_SOLDIER_H_

#include "../math.h"

#include "Entity.h"
#include "Inventory.h"

namespace blasted_city {

enum Rank
{
    kRecruit     = 0,
    kPrivate     = 10,
    kSergeant    = 50,
    kCaptain     = 100,
    kLieutenant  = 200,
    kMajor       = 500,
    kGeneral     = 1000
};

Rank GetNextRank(Rank rank);

class Soldier : public Entity
{
 public:
  Soldier() = delete;
  ~Soldier();

  void Attack();
  void Interact();
  void Reload();
  void SpecialAction();

  uint16_t hitpoints() const;
  uint16_t kill_count() const;
  Rank     rank() const;

  void AddKills(uint16_t count);
  void DropItem(uint16_t inventory_index);
  bool TakeItem(const ItemPtr &item);

 protected:
  explicit Soldier(GraphicsPtr graphics, InputPtr input, PhysicsPtr physics, Vec3 initialPose,
                   uint16_t hitpoints);

  virtual void UpdateImpl() override;

 private:
  virtual void AttackImpl() = 0;
  virtual void InteractImpl() = 0;
  virtual void SpecialActionImpl() = 0;

  Inventory    inventory_;
  uint16_t     hitpoints_;
  uint16_t     kill_count_;
  Rank         rank_;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_SOLDIER_H_
