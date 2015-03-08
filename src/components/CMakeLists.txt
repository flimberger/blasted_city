set(blasted_city_components_SRCS
    ComponentManager.cpp
  IGraphicsComponent.cpp
  IControlComponent.cpp
    InactiveControl.cpp
  IPhysicsComponent.cpp
  LocalInputImplementation.cc
  PhysicsImplementation.cc
  SpriteGraphicsImplementation.cc
)

add_library(components STATIC ${blasted_city_components_SRCS})
