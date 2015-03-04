#ifndef BLASTED_CITY_COMPONENTS_GRAPHICSCOMPONENT_H_
#define BLASTED_CITY_COMPONENTS_GRAPHICSCOMPONENT_H_

#include <memory>

namespace blasted_city {

class Entity;

class GraphicsComponent
{
 public:
  virtual ~GraphicsComponent();

  void Draw(const Entity &entity);

 private:
  virtual void DrawImpl(const Entity &entity) = 0;
};

} // namespace blasted_city

#endif // BLASTED_CITY_COMPONENTS_GRAPHICSCOMPONENT_H_
