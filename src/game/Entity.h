#ifndef BLASTED_CITY_GAME_ENTITY_H_
#define BLASTED_CITY_GAME_ENTITY_H_

#include "../math.h"

#include "../components/IGraphicsComponent.h"
#include "../components/IControlComponent.h"
#include "../components/IPhysicsComponent.h"

#include <memory>

namespace blasted_city {

using GraphicsPtr = std::shared_ptr<IGraphicsComponent>;
using ControlPtr  = std::shared_ptr<IControlComponent>;
using PhysicsPtr  = std::shared_ptr<IPhysicsComponent>;

class World;

class Entity
{
public:
    Entity() = delete;
    virtual ~Entity();

    void Draw() const;
    void Update(World &world);

    const Vec3 &GetPose() const;
    const Vec2 &GetSize() const;
    const Vec2 &GetSpeed() const;

    const ControlPtr  &GetControlComponent() const;
    const GraphicsPtr &GetGraphicsComponent() const;
    const PhysicsPtr  &GetPhysicsComponent() const;
    bool ShouldDelete() const;

    void Delete();
    void SetPose(Vec3 GetPose);
    void SetSize(Vec2 GetSize);
    void SetSpeed(Vec2 GetSpeed);

protected:
    Entity(GraphicsPtr graphics, ControlPtr control, PhysicsPtr physics, Vec3 GetPose, Vec2 GetSize);

    virtual void UpdateImpl(World &world);

private:
    Vec3         m_pose; // xy := position, z := rotation
    Vec2         m_size;
    Vec2         m_speed; // x := linear, y := rotational

    ControlPtr   m_control;
    GraphicsPtr  m_graphics;
    PhysicsPtr   m_physics;

    bool         m_shouldDelete;
};

} // namespace blasted_city

#endif // BLASTED_CITY_GAME_ENTITY_H_
