#include "global.h"
#include "math.h"

#include "components/ComponentManager.h"
#include "components/InactiveControl.h"
#include "components/LinearMoveControl.h"
#include "components/LocalInputImplementation.h"
#include "components/PhysicsImplementation.h"
#include "components/ProjectilePhysics.h"
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

#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <string>

using namespace blasted_city;

static constexpr auto *ASSET_PATH                  = "BLASTED_CITY_ASSET_PATH";
static constexpr auto PATH_SEPARATOR               = '/';
static constexpr auto *PROTO_SOLDIER_BITMAP_FILE   = "assets/sprites/proto_soldier.png";
static constexpr auto *SPRITE_FRAGMENT_SHADER_FILE = "src/shaders/sprite.fragment.glsl";
static constexpr auto *SPRITE_VERTEX_SHADER_FILE   = "src/shaders/sprite.vertex.glsl";
static constexpr auto *SPRITE_SHADER               = "spriteShader";
static constexpr auto MS_PER_FRAME                 = 1000.0 / 60.0;

static const char *progname;

static std::unique_ptr<Entity> CreateOpponent(const Vec3 &initialPose);
static std::unique_ptr<Entity> CreatePlayer(const Vec3 &initialPose);

int main(int argc, char *argv[]) {
    (void) argc;

    progname = argv[0];

    auto assets_path = std::string();
    const auto *assets_env = std::getenv(ASSET_PATH);

    if (assets_env)
        assets_path = assets_env;
    else {
        // TODO: fix logging
        std::fprintf(stderr, "%s: environment variable %s not set\n", progname, ASSET_PATH);

        const auto *cwd = getcwd(nullptr, 0); // memory must be freed

        assets_path = std::string(cwd);
        std::free(reinterpret_cast<void *>(const_cast<char *>(cwd)));
    }
    if (*--std::cend(assets_path) != PATH_SEPARATOR)
        assets_path.append(&PATH_SEPARATOR);

    // This contains the OpenGL initialization code, so must be called before the shaders are
    // created.
    auto &window = Window::GetInstance();

    auto &resMgr = ResourceManager::GetInstance();
    auto sprite_vertex_shader_file = assets_path + SPRITE_VERTEX_SHADER_FILE;
    auto sprite_fragment_shader_file = assets_path + SPRITE_FRAGMENT_SHADER_FILE;
    auto proto_soldier_bitmap_file = assets_path + PROTO_SOLDIER_BITMAP_FILE;

    resMgr.CreateShader(SPRITE_SHADER, sprite_vertex_shader_file, sprite_fragment_shader_file,
                         std::string());
    resMgr.CreateTexture(kProtoSoldierName, proto_soldier_bitmap_file);

    auto  soldierSprite = std::make_shared<Sprite>(resMgr.GetShader(SPRITE_SHADER),
                                                   resMgr.GetTexture(kProtoSoldierName));
    auto  bulletSprite  = std::make_shared<Sprite>(resMgr.GetShader(SPRITE_SHADER),
                                                   resMgr.GetTexture(kBlackPixel));
    auto  world         = std::unique_ptr<World>(new World(MapPtr(new Map)));
    auto &compMgr       = ComponentManager::GetInstance();

    compMgr.AddControlComponent(kProtoSoldierName,
                                std::shared_ptr<IControlComponent>(new InactiveControl));
    compMgr.AddGraphicsComponent(kProtoSoldierName,
                                 std::shared_ptr<IGraphicsComponent>(
                                     new SpriteGraphicsImplementation(soldierSprite)));
    compMgr.AddPhysicsComponent(kProtoSoldierName,
                                std::shared_ptr<IPhysicsComponent>(
                                    new PhysicsImplementation(world->GetMap())));
    compMgr.AddControlComponent(kBulletName,
                                std::shared_ptr<IControlComponent>(new LinearMoveControl));
    compMgr.AddGraphicsComponent(kBulletName,
                                 std::shared_ptr<IGraphicsComponent>(
                                     new SpriteGraphicsImplementation(bulletSprite)));
    compMgr.AddPhysicsComponent(kBulletName,
                                std::shared_ptr<IPhysicsComponent>(new ProjectilePhysics));

    world->AddEntity(CreatePlayer(Vec3(window.GetWidth() * 0.5f, window.GetHeight() * 0.25f,
                                       kPi2)));
    world->AddEntity(CreateOpponent(Vec3(window.GetWidth() * 0.25f, window.GetHeight() * 0.75f,
                                         kPi2 * -1.0f)));
    world->AddEntity(CreateOpponent(Vec3(window.GetWidth() * 0.75f, window.GetHeight() * 0.75f,
                                         kPi2 * -1.0f)));

    auto endTime       = 0.0; // s
    auto frameTime     = 0.0; // ms
    auto frameTimeSum  = 0.0; // ms
    auto intervalStart = glfwGetTime(); // s
    auto nFrames       = 0u;
    auto sleepTime     = useconds_t(0); // us
    auto startTime     = 0.0; // s

    while (true) {
        if (!window.IsOpen()) {
            break;
        }
        startTime = glfwGetTime();
        window.BeginFrame();
        world->Update();
        world->Draw();
        window.EndFrame();
        endTime = glfwGetTime();
        frameTime = (endTime - startTime) * 1000.0;
        frameTimeSum += frameTime;
        ++nFrames;
        if (endTime - intervalStart > 1.0) {
            std::fprintf(stdout, "average frame time %lf ms (%u FPS)\n", frameTimeSum / nFrames,
                         nFrames);
            frameTimeSum = 0.0;
            nFrames = 0u;
            intervalStart = endTime;
        }
        sleepTime = static_cast<useconds_t>((MS_PER_FRAME - frameTime) * 1000.0);
        if (sleepTime > 0.0) {
            usleep(sleepTime);
        }
    }

    return 0;
}

std::unique_ptr<Entity> CreateOpponent(const Vec3 &initialPose)
{
    auto &compMgr = ComponentManager::GetInstance();

    return std::unique_ptr<Entity>(new Gunner(compMgr.GetGraphicsComponent(kProtoSoldierName),
                                              compMgr.GetControlComponent(kProtoSoldierName),
                                              compMgr.GetPhysicsComponent(kProtoSoldierName),
                                              initialPose, 10));
}

static std::unique_ptr<Entity> CreatePlayer(const Vec3 &initialPose)
{
    auto &compMgr = ComponentManager::GetInstance();

    return std::unique_ptr<Entity>(new Burner(compMgr.GetGraphicsComponent(kProtoSoldierName),
                                              std::shared_ptr<IControlComponent>(
                                                  new LocalInputImplementation),
                                              compMgr.GetPhysicsComponent(kProtoSoldierName),
                                              initialPose, 10));
}
