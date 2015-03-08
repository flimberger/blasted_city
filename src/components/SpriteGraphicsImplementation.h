#ifndef BLASTED_CITY_COMPONENTS_SPRITEGRAPHICSIMPLEMENTATION_H_
#define BLASTED_CITY_COMPONENTS_SPRITEGRAPHICSIMPLEMENTATION_H_

#include "IGraphicsComponent.h"

#include <memory>

namespace blasted_city {

class Sprite;
using SpritePtr = std::shared_ptr<Sprite>;

class SpriteGraphicsImplementation : public IGraphicsComponent
{
 public:
  SpriteGraphicsImplementation(const SpritePtr &sprite);
  ~SpriteGraphicsImplementation();

private:
    virtual void DrawImpl(const Entity &entity) const override;

 SpritePtr  sprite_;
};

} // namespace blasted_city

#endif // BLASTED_CITY_COMPONENTS_SPRITEGRAPHICSIMPLEMENTATION_H_
