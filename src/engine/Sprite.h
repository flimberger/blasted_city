#ifndef BLASTED_CITY_ENGINE_SPRITE_H_
#define BLASTED_CITY_ENGINE_SPRITE_H_

#include <GL/glew.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include <memory>

namespace blasted_city {

class Shader;
using ShaderPtr = std::shared_ptr<Shader>;

class Texture;
using TexturePtr = std::shared_ptr<Texture>;

class Sprite
{
 public:
  Sprite(const ShaderPtr &shader, const TexturePtr &texture);
  ~Sprite();

  void Draw(const glm::vec2 &position, const glm::vec2 &size, float rotation) const;

 private:
  ShaderPtr   shader_;
  TexturePtr  texture_;
  GLuint      vao_;
  GLuint      vbo_;
};

} // namespace blasted_city

#endif // BLASTED_CITY_ENGINE_SPRITE_H_
