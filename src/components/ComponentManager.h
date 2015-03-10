#pragma once

#include "../base/Singleton.h"

#include <map>
#include <memory>
#include <string>

namespace blasted_city {

class IControlComponent;
class IGraphicsComponent;
class IPhysicsComponent;

using ControlPtr  = std::shared_ptr<IControlComponent>;
using GraphicsPtr = std::shared_ptr<IGraphicsComponent>;
using PhysicsPtr  = std::shared_ptr<IPhysicsComponent>;

class ComponentManagerImpl
{
public:
    ~ComponentManagerImpl();

    void AddControlComponent(const std::string &id,
                             const ControlPtr &controlPtr);
    void AddGraphicsComponent(const std::string &id,
                              const GraphicsPtr &graphicsPtr);
    void AddPhysicsComponent(const std::string &id,
                             const PhysicsPtr &physicsPtr);

    const ControlPtr  &GetControlComponent(const std::string &id);
    const GraphicsPtr &GetGraphicsComponent(const std::string &id);
    const PhysicsPtr  &GetPhysicsComponent(const std::string &id);

private:
    friend class Singleton<ComponentManagerImpl>;

    ComponentManagerImpl();

    std::map<std::string, ControlPtr>   m_controlComponents;
    std::map<std::string, GraphicsPtr>  m_graphicsComponents;
    std::map<std::string, PhysicsPtr>   m_physicsComponents;
};

using ComponentManager = Singleton<ComponentManagerImpl>;

} // namespace blasted_city
