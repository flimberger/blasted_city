#ifndef BLASTED_CITY_ENGINE_TEXTURE_H_
#define BLASTED_CITY_ENGINE_TEXTURE_H_

#include "../global.h"

#include <GL/glew.h>

#include <memory>

namespace blasted_city {

enum TextureFormat {
  kU8rgb,
  kU8rgba
};

class Texture
{
 public:
  Texture();
  Texture(const Texture &) = delete;
  Texture(Texture &&other);
  ~Texture();

  static std::unique_ptr<Texture> CreateFromData(u_int width, u_int height, const u_char *data,
                                                 TextureFormat format);
  static std::unique_ptr<Texture> CreateFromJPEGFile(const char *path);
  static std::unique_ptr<Texture> CreateFromPNGFile(const char *path);

  void Bind() const;

 private:
  GLuint handle_;
};

} // namespace blasted_city

#endif // BLASTED_CITY_ENGINE_TEXTURE_H_
