#ifndef BLASTED_CITY_ENGINE_SHADER_H_
#define BLASTED_CITY_ENGINE_SHADER_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include <memory>

namespace blasted_city {

class Shader
{
 public:
  Shader();
  Shader(const Shader &) = delete;
  Shader(Shader &&other);
  ~Shader();

  static std::unique_ptr<Shader> Create(const char *vertex_shader_source,
                                        const char *fragment_shader_source,
                                        const char *geometry_shader_source);

  void SetInteger1(const char *name, GLint value) const;
  void SetMatrix4f(const char *name, const glm::mat4 &value) const;
  void Use() const;

 private:
  GLuint handle_;
};

} // namespace blasted_city

#endif // BLASTED_CITY_ENGINE_SHADER_H_
