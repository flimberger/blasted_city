#include "ComponentManager.h"

namespace blasted_city {

ComponentManager::ComponentManager() = default;
ComponentManager::~ComponentManager() = default;

ComponentManager &ComponentManager::GetInstance()
{
    static ComponentManager s_instance;

    return s_instance;
}

void ComponentManager::AddControlComponent(const std::string &id,
                                           const ControlPtr &controlPtr)
{
    m_controlComponents[id] = controlPtr;
}

void ComponentManager::AddGraphicsComponent(const std::string &id,
                                            const GraphicsPtr &graphicsPtr)
{
    m_graphicsComponents[id] = graphicsPtr;
}

void ComponentManager::AddPhysicsComponent(const std::string &id,
                                           const PhysicsPtr &physicsPtr)
{
    m_physicsComponents[id] = physicsPtr;
}

const ControlPtr &ComponentManager::GetControlComponent(const std::string &id)
{
    return m_controlComponents[id];
}

const GraphicsPtr &ComponentManager::GetGraphicsComponent(const std::string &id)
{
    return m_graphicsComponents[id];
}

const PhysicsPtr &ComponentManager::GetPhysicsComponent(const std::string &id)
{
    return m_physicsComponents[id];
}

} // namespace blasted_city
