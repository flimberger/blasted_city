set(blasted_city_engine_SRCS
    ResourceManager.cpp
    Shader.cc
  Sprite.cc
  Texture.cc
  Window.cc
)

include_directories(${OpenGL_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})
add_library(engine STATIC ${blasted_city_engine_SRCS})
