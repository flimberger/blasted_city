#ifndef BLASTED_CITY_ENGINE_WINDOW_H_
#define BLASTED_CITY_ENGINE_WINDOW_H_

#include "../global.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace blasted_city {

class Window
{
 public:
  Window(const Window &) = delete;
  ~Window();

    static Window &GetInstance();

    size_t  GetHeight() const;
    size_t  GetWidth() const;
  bool         is_open() const;
  bool        *key_states() const;

  void         BeginFrame() const;
  void         EndFrame() const;

  void         Shutdown();

 private:
  Window();

  void Init();

  GLFWwindow  *window_;

  friend class Window;
};

} // namespace blasted_city

#endif // BLASTED_CITY_ENGINE_WINDOW_H_
