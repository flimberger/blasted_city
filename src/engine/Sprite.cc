#include "Sprite.h"

#include "Shader.h"
#include "Texture.h"
#include "Window.h"

#include <glm/gtc/matrix_transform.hpp>

namespace blasted_city {

static const float kQuadVertices[] = {
// vertex coordinates, texture coordinates
  0.0f, 1.0f,  0.0f, 1.0f,
  1.0f, 0.0f,  1.0f, 0.0f,
  0.0f, 0.0f,  0.0f, 0.0f,
  0.0f, 1.0f,  0.0f, 1.0f,
  1.0f, 1.0f,  1.0f, 1.0f,
  1.0f, 0.0f,  1.0f, 0.0f
};

Sprite::Sprite(const ShaderPtr &shader, const TexturePtr &texture)
  : shader_(shader),
    texture_(texture),
    vao_(0),
    vbo_(0)
{}

Sprite::~Sprite()
{
  if (vbo_) {
    glDeleteBuffers(1, &vbo_);
  }
  if (vao_) {
    glDeleteVertexArrays(1, &vao_);
  }
}

void Sprite::Draw(const glm::vec2 &position, const glm::vec2 &size, float rotation) const
{
  shader_->Use();
  shader_->SetInteger1("image", 0);

  glm::mat4 model = glm::translate(glm::mat4(), glm::vec3(position, 0.0f));

  model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
  model = glm::rotate(model, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
  model = glm::scale(model, glm::vec3(size, 0.0f));
  shader_->SetMatrix4f("model", model);
  glActiveTexture(GL_TEXTURE0);
  texture_->Bind();
  glBindVertexArray(vao_);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindTexture(GL_TEXTURE_2D, 0);
  glBindVertexArray(0);
}

void Sprite::Init()
{
  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(kQuadVertices), kQuadVertices, GL_STATIC_DRAW);
  glBindVertexArray(vao_);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), static_cast<GLvoid *>(0));
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

} // namespace blasted_city
