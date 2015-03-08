#include "global.h"
#include "math.h"

#include "components/InactiveControl.h"
#include "components/LocalInputImplementation.h"
#include "components/PhysicsImplementation.h"
#include "components/SpriteGraphicsImplementation.h"

#include "engine/ResourceManager.h"
#include "engine/Shader.h"
#include "engine/Sprite.h"
#include "engine/Texture.h"
#include "engine/Window.h"

#include "game/Map.h"
#include "game/World.h"
#include "game/classes/Burner.h"
#include "game/classes/Gunner.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <unistd.h>

using namespace blasted_city;

static constexpr auto PROTO_SOLDIER_TEXTURE       = "protoSoldier";
static constexpr auto PROTO_SOLDIER_BITMAP_FILE   = "/home/flo/devel/blasted_city/assets/sprites/proto_soldier.png";
static constexpr auto SPRITE_FRAGMENT_SHADER_FILE = "/home/flo/devel/blasted_city/src/shaders/sprite.fragment.glsl";
static constexpr auto SPRITE_VERTEX_SHADER_FILE   = "/home/flo/devel/blasted_city/src/shaders/sprite.vertex.glsl";
static constexpr auto SPRITE_SHADER               = "spriteShader";
static constexpr auto MS_PER_FRAME                = 1000.0 / 60.0;

static std::unique_ptr<Entity> CreateOpponent(const World &world, const Vec3 &initialPose);
static std::unique_ptr<Entity> CreatePlayer(const World &world, const Vec3 &initialPose);

int main() {
    auto &window = Window::GetInstance();
    auto &resMgr = ResourceManager::GetInstance();

    resMgr.CreateShader(SPRITE_SHADER, SPRITE_VERTEX_SHADER_FILE, SPRITE_FRAGMENT_SHADER_FILE,
                         std::string());
    resMgr.CreateTexture(PROTO_SOLDIER_TEXTURE, PROTO_SOLDIER_BITMAP_FILE);

    auto  world   = std::unique_ptr<World>(new World(MapPtr(new Map)));

    world->AddEntity(CreatePlayer(*world, Vec3(window.GetWidth() * 0.5f,
                                               window.GetHeight() * 0.25f, kPi2)));
    world->AddEntity(CreateOpponent(*world, Vec3(window.GetWidth() * 0.25f,
                                                 window.GetHeight() * 0.75f, kPi2 * -1.0f)));
    world->AddEntity(CreateOpponent(*world, Vec3(window.GetWidth() * 0.75f,
                                                 window.GetHeight() * 0.75f, kPi2 * -1.0f)));

    auto start      = 0.0;
    auto sleep_time = 0.0;

    while (true) {
        if (!window.is_open()) {
            break;
        }
        start = glfwGetTime();
        window.BeginFrame();
        world->Update();
        world->Draw();
        window.EndFrame();
        sleep_time = start + MS_PER_FRAME - glfwGetTime();
        if (sleep_time > 0.0) {
            usleep(static_cast<useconds_t>(sleep_time));
        } else {
            std::fprintf(stderr, "lag of %lf ms\n", sleep_time * -1.0);
        }
    }

    return 0;
}

std::unique_ptr<Entity> CreateOpponent(const World &world, const Vec3 &initialPose)
{
    auto &resMgr   = ResourceManager::GetInstance();
    auto  sprite   = std::make_shared<Sprite>(resMgr.GetShader(SPRITE_SHADER),
                                              resMgr.GetTexture(PROTO_SOLDIER_TEXTURE));
    auto  graphics = std::unique_ptr<IGraphicsComponent>(new SpriteGraphicsImplementation(sprite));
    auto  input    = std::unique_ptr<IControlComponent>(new InactiveControl);
    auto  physics  = std::unique_ptr<IPhysicsComponent>(new PhysicsImplementation(world.GetMap()));

    return std::unique_ptr<Entity>(new Gunner(std::move(graphics), std::move(input),
                                              std::move(physics), initialPose, 10));
}

static std::unique_ptr<Entity> CreatePlayer(const World &world, const Vec3 &initialPose)
{
    auto &resMgr   = ResourceManager::GetInstance();
    auto  sprite   = std::make_shared<Sprite>(resMgr.GetShader(SPRITE_SHADER),
                                              resMgr.GetTexture(PROTO_SOLDIER_TEXTURE));
    auto  graphics = std::unique_ptr<IGraphicsComponent>(new SpriteGraphicsImplementation(sprite));
    auto  input    = std::unique_ptr<IControlComponent>(new LocalInputImplementation);
    auto  physics  = std::unique_ptr<IPhysicsComponent>(new PhysicsImplementation(world.GetMap()));

    return std::unique_ptr<Entity>(new Burner(std::move(graphics), std::move(input),
                                              std::move(physics), initialPose, 10));
}
