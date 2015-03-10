#include "ComponentManager.h"

namespace blasted_city {

ComponentManagerImpl::ComponentManagerImpl() = default;
ComponentManagerImpl::~ComponentManagerImpl() = default;

void ComponentManagerImpl::AddControlComponent(const std::string &id,
                                           const ControlPtr &controlPtr)
{
    m_controlComponents[id] = controlPtr;
}

void ComponentManagerImpl::AddGraphicsComponent(const std::string &id,
                                            const GraphicsPtr &graphicsPtr)
{
    m_graphicsComponents[id] = graphicsPtr;
}

void ComponentManagerImpl::AddPhysicsComponent(const std::string &id,
                                           const PhysicsPtr &physicsPtr)
{
    m_physicsComponents[id] = physicsPtr;
}

const ControlPtr &ComponentManagerImpl::GetControlComponent(const std::string &id)
{
    return m_controlComponents[id];
}

const GraphicsPtr &ComponentManagerImpl::GetGraphicsComponent(const std::string &id)
{
    return m_graphicsComponents[id];
}

const PhysicsPtr &ComponentManagerImpl::GetPhysicsComponent(const std::string &id)
{
    return m_physicsComponents[id];
}

} // namespace blasted_city
