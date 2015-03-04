#include "Window.h"

#include "../global.h"

namespace blasted_city {

static constexpr size_t kNumberOfKeys  = 512;
static constexpr int    kWindowWidth   = 800;
static constexpr int    kWindowHeight  = 600;
static const     char  *kWindowTitle   ="Blasted City";

static Window *g_window_instance;
static bool    g_key_press_table[kNumberOfKeys];

void KeyCallback(GLFWwindow *window, int key, int scan_code, int action, int mode)
{
  (void) window;
  (void) scan_code;
  (void) mode;

  if (action == GLFW_PRESS) {
    g_key_press_table[key] = true;
  } else if (action == GLFW_RELEASE){
    g_key_press_table[key] = false;
  }
}

void MouseCallback(GLFWwindow *window, double x_position, double y_position)
{
  (void) window;
  (void) x_position;
  (void) y_position;
}

Window::Window()
  : window_(nullptr)
{}

Window::~Window()
{
  Shutdown();
}

Window *Window::instance()
{
  if (!g_window_instance) {
    g_window_instance = new Window;
    g_window_instance->Init();
  }

  return g_window_instance;
}

std::size_t Window::height() const
{
  int height;

  glfwGetWindowSize(window_, NULL, &height);

  return static_cast<std::size_t>(height);
}

std::size_t Window::width() const
{
  int width;

  glfwGetWindowSize(window_, &width, NULL);

  return static_cast<std::size_t>(width);
}

bool Window::is_open() const
{
  return !glfwWindowShouldClose(window_);
}

void Window::BeginFrame() const
{
  glfwPollEvents();
  glClear(GL_COLOR_BUFFER_BIT);
}

bool *Window::key_states() const
{
  return &g_key_press_table[0];
}

void Window::EndFrame() const
{
  glfwSwapBuffers(window_);
}

void Window::Shutdown()
{
  if (window_) {
    glfwTerminate();
    window_ = nullptr;
  }
}

void Window::Init()
{
  if (!glfwInit()) {
    Terminate("Graphics Error: Failed to initialize GLFW");
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  window_ = glfwCreateWindow(kWindowWidth, kWindowHeight, kWindowTitle, NULL, NULL);
  if (!window_) {
    Terminate("Graphics Error: Failed to create GLFW window");
  }
  glfwMakeContextCurrent(window_);
  glewExperimental = GL_TRUE;

  GLenum err = glewInit();

  if (err != GLEW_OK) {
    std::string error_message("Graphics Error: Failed to initialize GLEW:");

    error_message += std::string(reinterpret_cast<const char *>(glewGetErrorString(err)));
    Terminate(error_message.c_str());
  }
  glViewport(0, 0, kWindowWidth, kWindowHeight);
  glfwSetKeyCallback(window_, KeyCallback);
  glfwSetCursorPosCallback(window_, MouseCallback);
  glEnable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(0.1f, 0.05f, 0.025f, 1.0f);
}

} // namespace blasted_city