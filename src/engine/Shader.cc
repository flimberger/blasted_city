#include "Shader.h"

#include "Window.h"

#include "../global.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cassert>

namespace blasted_city {

namespace {

enum ShaderType {
  kVertexShader,
  kFragmentShader,
  kGeometryShader
};

class ShaderObject
{
 public:
  ShaderObject(const ShaderObject &) = delete;
  ShaderObject(ShaderObject &&) = default;
  ~ShaderObject();

  static ShaderObject Compile(ShaderType type, const char *shader_source);

  GLuint handle() const;

 private:
  ShaderObject(ShaderType type);

  GLuint      handle_;
  ShaderType  type_;
};

const GLuint kOpenGLShaderTypes[] = {
  GL_VERTEX_SHADER,   // kVertexShader
  GL_FRAGMENT_SHADER, // kFragmentShader
  GL_GEOMETRY_SHADER  // kGeometryShader
};

StdUniquePtr<char>
GetOpenGlInfolog(GLuint handle, PFNGLGETSHADERIVPROC gl_getIv,
                 PFNGLGETSHADERINFOLOGPROC gl_getInfolog)
{
  GLint log_length;

  gl_getIv(handle, GL_INFO_LOG_LENGTH, &log_length);

  auto infolog = StdLibAllocate<char>(static_cast<std::size_t>(log_length));

  gl_getInfolog(handle, log_length, NULL, infolog.get());

  return infolog;
}

ShaderObject::ShaderObject(ShaderType type)
  : handle_(0),
    type_(type)
{}

ShaderObject::~ShaderObject()
{
  if (handle_) {
    glDeleteShader(handle_);
  }
}

ShaderObject ShaderObject::Compile(ShaderType type, const char *shader_source)
{
  auto shader = ShaderObject(type);

  shader.handle_ = glCreateShader(kOpenGLShaderTypes[type]);
  if (!shader.handle_) {
    Terminate("Graphics Error: Failed to create shader handle.");
  }
  glShaderSource(shader.handle_, 1, &shader_source, nullptr);
  glCompileShader(shader.handle_);

  GLint status;

  glGetShaderiv(shader.handle_, GL_COMPILE_STATUS, &status);
  if (!status) {
    auto errorlog = GetOpenGlInfolog(shader.handle_, glGetShaderiv, glGetShaderInfoLog);

    Terminate(errorlog.get());
  }

  return shader;
}

GLuint ShaderObject::handle() const
{
  return handle_;
}

} // namespace

Shader::Shader()
  : handle_(0)
{}

Shader::Shader(Shader &&other) = default;

Shader::~Shader()
{
  if (handle_) {
    glDeleteProgram(handle_);
  }
}

std::unique_ptr<Shader> Shader::Create(const char *vertex_shader_source,
                                       const char *fragment_shader_source,
                                       const char *geometry_shader_source)
{
  assert(vertex_shader_source);
  assert(fragment_shader_source);

  auto vertex_shader    = ShaderObject::Compile(kVertexShader, vertex_shader_source);
  auto fragment_shader  = ShaderObject::Compile(kFragmentShader, fragment_shader_source);
  auto shader_program   = std::unique_ptr<Shader>(new Shader);

  shader_program->handle_ = glCreateProgram();
  if (!shader_program->handle_) {
    Terminate("Graphics Error: Failed to create shader program handle");
  }
  glAttachShader(shader_program->handle_, vertex_shader.handle());
  glAttachShader(shader_program->handle_, fragment_shader.handle());
  if (geometry_shader_source) {
    auto geometry_shader = ShaderObject::Compile(kGeometryShader, geometry_shader_source);

    glAttachShader(shader_program->handle_, geometry_shader.handle());
  }
  glLinkProgram(shader_program->handle_);

  GLint status;

  glGetProgramiv(shader_program->handle_, GL_LINK_STATUS, &status);
  if (!status) {
    auto errorlog = GetOpenGlInfolog(shader_program->handle_, glGetProgramiv,
                                     glGetProgramInfoLog);

    Terminate(errorlog.get());
  }

  shader_program->Use();
  auto *win = Window::instance();
  auto projection = glm::ortho(0.0f, static_cast<GLfloat>(win->width()),
                               static_cast<GLfloat>(win->height()), 0.0f, -1.0f, 1.0f);

  shader_program->SetMatrix4f("projection", projection);
  glUseProgram(0);

  return shader_program;
}

void Shader::SetInteger1(const char *name, GLint value) const
{
  auto id = glGetUniformLocation(handle_, name);

  glUniform1i(id, value);
}

void Shader::SetMatrix4f(const char *name, const glm::mat4 &value) const
{
  auto id = glGetUniformLocation(handle_, name);

  glUniformMatrix4fv(id, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::Use() const
{
  glUseProgram(handle_);
}

} // namespace blasted_city
