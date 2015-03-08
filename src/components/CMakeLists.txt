set(blasted_city_components_SRCS
    ComponentManager.cpp
    IGraphicsComponent.cpp
    IControlComponent.cpp
    InactiveControl.cpp
    IPhysicsComponent.cpp
    LinearMoveControl.cpp
    LocalInputImplementation.cc
    PhysicsImplementation.cc
    ProjectilePhysics.cpp
    SpriteGraphicsImplementation.cc
)

add_library(components STATIC ${blasted_city_components_SRCS})
