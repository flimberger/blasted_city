#ifndef BLASTED_CITY_COMPONENTS_PHYSICSCOMPONENT_H_
#define BLASTED_CITY_COMPONENTS_PHYSICSCOMPONENT_H_

namespace blasted_city {

class Entity;

class PhysicsComponent
{
 public:
  virtual ~PhysicsComponent();

  void Update(Entity &entity);

 private:
  virtual void UpdateImpl(Entity &entity) = 0;
};

} // namespace blasted_city

#endif // BLASTED_CITY_COMPONENTS_PHYSICSCOMPONENT_H_
