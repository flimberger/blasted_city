#ifndef BLASTED_CITY_ENGINE_WINDOW_H_
#define BLASTED_CITY_ENGINE_WINDOW_H_

#include "../global.h"

#include "../base/Singleton.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace blasted_city {

class WindowImpl
{
 public:
    WindowImpl(const WindowImpl &) = delete;
    ~WindowImpl();

    size_t  GetHeight() const;
    size_t  GetWidth() const;
  bool         is_open() const;
  bool        *key_states() const;

  void         BeginFrame() const;
  void         EndFrame() const;

  void         Shutdown();

private:
    friend class Singleton<WindowImpl>;

    WindowImpl();

  void Init();

  GLFWwindow  *window_;
};

using Window = Singleton<WindowImpl>;

} // namespace blasted_city

#endif // BLASTED_CITY_ENGINE_WINDOW_H_
