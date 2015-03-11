#include "Window.h"

#include "../global.h"

namespace blasted_city {

namespace {

static constexpr int    kWindowWidth   = 800;
static constexpr int    kWindowHeight  = 600;
static const     char  *kWindowTitle   ="Blasted City";

static const int  kGLFWTranslationTable[] = {
    // numbers
    GLFW_KEY_0, // kKey0
    GLFW_KEY_1, // kKey1
    GLFW_KEY_2, // kKey2
    GLFW_KEY_3, // kKey3
    GLFW_KEY_4, // kKey4
    GLFW_KEY_5, // kKey5
    GLFW_KEY_6, // kKey6
    GLFW_KEY_7, // kKey7
    GLFW_KEY_8, // kKey8
    GLFW_KEY_9, // kKey9
    // letters
    GLFW_KEY_A, // kKeyA
    GLFW_KEY_B, // kKeyB
    GLFW_KEY_C, // kKeyC
    GLFW_KEY_D, // kKeyD
    GLFW_KEY_E, // kKeyE
    GLFW_KEY_F, // kKeyF
    GLFW_KEY_G, // kKeyG
    GLFW_KEY_H, // kKeyH
    GLFW_KEY_I, // kKeyI
    GLFW_KEY_J, // kKeyJ
    GLFW_KEY_K, // kKeyK
    GLFW_KEY_L, // kKeyL
    GLFW_KEY_M, // kKeyM
    GLFW_KEY_N, // kKeyN
    GLFW_KEY_O, // kKeyO
    GLFW_KEY_P, // kKeyP
    GLFW_KEY_Q, // kKeyQ
    GLFW_KEY_R, // kKeyR
    GLFW_KEY_S, // kKeyS
    GLFW_KEY_T, // kKeyT
    GLFW_KEY_U, // kKeyU
    GLFW_KEY_V, // kKeyV
    GLFW_KEY_W, // kKeyW
    GLFW_KEY_X, // kKeyX
    GLFW_KEY_Y, // kKeyY
    GLFW_KEY_Z, // kKeyZ
    // stuff
    GLFW_KEY_ENTER,         // kKeyEnter
    GLFW_KEY_ESCAPE,        // kKeyEscape
    GLFW_KEY_LEFT_ALT,      // kKeyLeftAlt
    GLFW_KEY_LEFT_CONTROL,  // kKeyLeftControl
    GLFW_KEY_LEFT_SHIFT,    // kKeyLeftShift
    GLFW_KEY_RIGHT_ALT,     // kKeyRightAlt
    GLFW_KEY_RIGHT_CONTROL, // kKeyRightControl
    GLFW_KEY_RIGHT_SHIFT,   // kKeyRightShift
    GLFW_KEY_SPACE,         // kKeySpace
    // arrows
    GLFW_KEY_UP,    // kKeyUp
    GLFW_KEY_LEFT,  // kKeyLeft
    GLFW_KEY_DOWN,  // kKeyDown
    GLFW_KEY_RIGHT, // kKeyRight
};

} // namespace

WindowImpl::WindowImpl()
  : m_window(nullptr)
{
    if (!glfwInit()) {
        Terminate("Graphics Error: Failed to initialize GLFW");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    m_window = glfwCreateWindow(kWindowWidth, kWindowHeight, kWindowTitle, NULL, NULL);
    if (!m_window) {
        Terminate("Graphics Error: Failed to create GLFW window");
    }
    glfwMakeContextCurrent(m_window);
    glewExperimental = GL_TRUE;

    GLenum err = glewInit();

    if (err != GLEW_OK) {
        Terminate("Graphics Error: Failed to initialize GLEW:"
                  + std::string(reinterpret_cast<const char *>(glewGetErrorString(err))));
    }
    glViewport(0, 0, kWindowWidth, kWindowHeight);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.1f, 0.05f, 0.025f, 1.0f);
}

WindowImpl::~WindowImpl()
{
    Shutdown();
}

size_t WindowImpl::GetHeight() const
{
    int height;

    glfwGetWindowSize(m_window, NULL, &height);

    return static_cast<size_t>(height);
}

size_t WindowImpl::GetWidth() const
{
    int width;

    glfwGetWindowSize(m_window, &width, NULL);

    return static_cast<size_t>(width);
}

bool WindowImpl::IsOpen() const
{
    return !glfwWindowShouldClose(m_window);
}

void WindowImpl::BeginFrame()
{
    glfwPollEvents();
    ProcessKeys();
    glClear(GL_COLOR_BUFFER_BIT);
}

const std::array<KeyState, kNumberOfKeySymbols> &WindowImpl::GetKeyStates() const
{
    return m_keyPressTable;
}

void WindowImpl::EndFrame() const
{
    glfwSwapBuffers(m_window);
}

void WindowImpl::Shutdown()
{
    if (m_window) {
        glfwTerminate();
        m_window = nullptr;
    }
}

void WindowImpl::ProcessKeys()
{
    for (u_int key = kKey0; key < kNumberOfKeySymbols; ++key) {
        bool keyPressed = glfwGetKey(m_window, kGLFWTranslationTable[key]);

        if (keyPressed) {
            if (!std::get<kKeyPressed>(m_keyPressTable[key])) {
                m_keyPressTable[key] = std::make_tuple(true, true, false);
            } else {
                m_keyPressTable[key] = std::make_tuple(true, false, false);
            }
        } else {
            if (std::get<kKeyPressed>(m_keyPressTable[key])) {
                m_keyPressTable[key] = std::make_tuple(false, false, true);
            } else {
                m_keyPressTable[key] = std::make_tuple(false, false, false);
            }
        }
    }
}

} // namespace blasted_city
