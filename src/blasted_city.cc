#include "global.h"

#include "components/LocalInputImplementation.h"
#include "components/PhysicsImplementation.h"
#include "components/SpriteGraphicsImplementation.h"

#include "engine/Shader.h"
#include "engine/Sprite.h"
#include "engine/Texture.h"
#include "engine/Window.h"

#include "game/World.h"
#include "game/classes/Burner.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <unistd.h>

using namespace blasted_city;

static constexpr auto kMSperFrame = double(1000.0/60.0);

int main() {
  auto window  = Window::instance();
  auto world   = std::unique_ptr<World>(new World);

  {
    auto vertex_shader   = ReadTextFile(
                "/home/flo/devel/blasted_city/src/shaders/sprite.vertex.glsl");
    auto fragment_shader = ReadTextFile(
                "/home/flo/devel/blasted_city/src/shaders/sprite.fragment.glsl");
    auto sprite_shader   = std::shared_ptr<Shader>(Shader::Create(vertex_shader.c_str(),
                                                                  fragment_shader.c_str(),
                                                                  nullptr));
    auto texture         = std::shared_ptr<Texture>(Texture::CreateFromPNGFile(
                                  "/home/flo/devel/blasted_city/assets/sprites/proto_soldier.png"));
    auto sprite          = std::make_shared<Sprite>(sprite_shader, texture);

    sprite->Init();

    auto graphics = std::unique_ptr<GraphicsComponent>(new SpriteGraphicsImplementation(sprite));
    auto input    = std::unique_ptr<InputComponent>(new LocalInputImplementation);
    auto physics  = std::unique_ptr<PhysicsComponent>(new PhysicsImplementation);
    auto player   = std::unique_ptr<Entity>(new Burner(std::move(graphics), std::move(input),
                                                       std::move(physics), 10));

    world->AddEntity(std::move(player));
  }

  auto start      = 0.0;
  auto sleep_time = 0.0;

  while (true) {
    if (!window->is_open()) {
      break;
    }
    start = glfwGetTime();
    window->BeginFrame();
    world->Draw();
    window->EndFrame();
    sleep_time = start + kMSperFrame - glfwGetTime();
    if (sleep_time > 0.0) {
      usleep(static_cast<useconds_t>(sleep_time));
    } else {
      std::fprintf(stderr, "lag of %lf ms\n", sleep_time * -1.0);
    }
  }

  window->Shutdown();
  return 0;
}
