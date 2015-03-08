#ifndef BLASTED_CITY_COMPONENTS_PHYSICSCOMPONENT_H_
#define BLASTED_CITY_COMPONENTS_PHYSICSCOMPONENT_H_

namespace blasted_city {

class Entity;
class World;

class IPhysicsComponent
{
 public:
  virtual ~IPhysicsComponent();

  void Update(World &world, Entity &entity);

 private:
  virtual void UpdateImpl(World &world, Entity &entity) = 0;
};

} // namespace blasted_city

#endif // BLASTED_CITY_COMPONENTS_PHYSICSCOMPONENT_H_
