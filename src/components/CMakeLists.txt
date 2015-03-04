set(blasted_city_components_SRCS
  GraphicsComponent.cc
  InputComponent.cc
  LocalInputImplementation.cc
  PhysicsComponent.cc
  PhysicsImplementation.cc
  SpriteGraphicsImplementation.cc
)

add_library(components STATIC ${blasted_city_components_SRCS})
