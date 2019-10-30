find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(blasted_city_engine_SRCS
    ResourceManager.cpp
    Shader.cc
    Sprite.cc
    Texture.cc
    Window.cc
)

add_library(engine STATIC ${blasted_city_engine_SRCS})
target_link_libraries(engine
    OpenGL::GL
    GLEW::glew)
