#ifndef BLASTED_CITY_COMPONENTS_GRAPHICSCOMPONENT_H_
#define BLASTED_CITY_COMPONENTS_GRAPHICSCOMPONENT_H_

#include <memory>

namespace blasted_city {

class Entity;

class IGraphicsComponent
{
public:
    virtual ~IGraphicsComponent();

    void Draw(const Entity &entity) const;

private:
    virtual void DrawImpl(const Entity &entity) const = 0;
};

} // namespace blasted_city

#endif // BLASTED_CITY_COMPONENTS_GRAPHICSCOMPONENT_H_
