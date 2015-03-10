find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)

add_subdirectory(base)
add_subdirectory(components)
add_subdirectory(engine)
add_subdirectory(game)
# add_subdirectory(physics)

add_executable(blasted_city blasted_city.cc global.cc)
target_link_libraries(blasted_city
  components
  engine
  game
#   physics
  ${GLEW_LIBRARIES}
  ${GLFW_STATIC_LIBRARIES}
  ${PNG_LIBRARIES}
  ${JPEG_LIBRARIES}
)
