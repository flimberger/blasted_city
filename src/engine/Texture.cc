#include "Texture.h"

#include <jpeglib.h>
#include <png.h>

#include <cstdio>
#include <string>

static const struct {
  GLuint format;
  GLuint size;
} kImageFormatTable[] = {
  { GL_RGB,  GL_UNSIGNED_BYTE }, // U8_RGB
  { GL_RGBA, GL_UNSIGNED_BYTE }  // U8_RGBA
};

namespace blasted_city {

Texture::Texture()
  : handle_(0)
{}

Texture::Texture(Texture &&other) = default;

Texture::~Texture()
{
  if (handle_) {
    glDeleteTextures(1, &handle_);
  }
}

std::unique_ptr<Texture> Texture::CreateFromData(u_int width, u_int height, const u_char *data,
                                                 TextureFormat format)
{
  auto texture = std::unique_ptr<Texture>(new Texture);

  glGenTextures(1, &texture->handle_);
  glBindTexture(GL_TEXTURE_2D, texture->handle_);
  glTexImage2D(GL_TEXTURE_2D, 0, static_cast<GLint>(kImageFormatTable[format].format),
               static_cast<GLsizei>(width), static_cast<GLsizei>(height), 0,
               kImageFormatTable[format].format, kImageFormatTable[format].size, data);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//  glGenerateMipmap(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, 0);

  return texture;
}

std::unique_ptr<Texture> Texture::CreateFromJPEGFile(const std::string &path)
{
  struct jpeg_decompress_struct compression_info;
  struct jpeg_error_mgr error_manager;

  compression_info.err = jpeg_std_error(&error_manager);
  jpeg_create_decompress(&compression_info);

  FILE *fp = std::fopen(path.c_str(), "r");

  if (!fp) {
    Terminate("Failed to open file " + path);
  }
  jpeg_stdio_src(&compression_info, fp);
  jpeg_read_header(&compression_info, true);
  jpeg_start_decompress(&compression_info);

  u_int width  = compression_info.image_width;
  u_int height = compression_info.image_height;
  auto data = StdLibAllocate<u_char>(width * height
                                     * static_cast<u_int>(compression_info.num_components));

  u_char *row = data.get();

  while(compression_info.output_scanline < compression_info.output_height) {
    jpeg_read_scanlines(&compression_info, &row, 1);
    row += static_cast<off_t>(width) * compression_info.num_components;
  }
  jpeg_finish_decompress(&compression_info);
  jpeg_destroy_decompress(&compression_info);

  return CreateFromData(width, height, data.get(), kU8rgb);
}

std::unique_ptr<Texture> Texture::CreateFromPNGFile(const std::string &path)
{
  FILE *fp = std::fopen(path.c_str(), "r");

  if (!fp) {
    Terminate("Failed to open file " + path);
  }

  png_struct *png_pointer = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr,
                                                   nullptr);

  if (!png_pointer) {
    std::fclose(fp);
    Terminate("Out of memory");
  }

  png_info *infoPointer = png_create_info_struct(png_pointer);

  if (!infoPointer) {
      png_destroy_read_struct(&png_pointer, NULL, NULL);
      std::fclose(fp);
      Terminate("Out of memory");
  }
  if (setjmp(png_jmpbuf(png_pointer))) {
    png_destroy_read_struct(&png_pointer, &infoPointer, NULL);
    std::fclose(fp);
    Terminate("Error while reading from file " + path);
  }
  png_init_io(png_pointer, fp);
  png_read_info(png_pointer, infoPointer);

  u_int width = png_get_image_width(png_pointer, infoPointer);
  u_int height = png_get_image_height(png_pointer, infoPointer);

  size_t row_size = png_get_rowbytes(png_pointer, infoPointer);
  // TODO: don't leak libpng internal structures
  auto row_pointers = StdLibAllocate<u_char *>(height);
  auto data = StdLibAllocate<u_char>(height * row_size);

  // the row pointers are set in reverse because of the different coordinate
  // systems of OpenGL and PNG
  for (u_int i = 0; i < height; ++i) {
    row_pointers.get()[height - 1 - i] = data.get() + i * row_size;
  }
  if (setjmp(png_jmpbuf(png_pointer))) {
    png_destroy_read_struct(&png_pointer, &infoPointer, NULL);
    std::fclose(fp);
    Terminate("Error while reading from file " + path);
  }
  png_read_image(png_pointer, row_pointers.get());
  png_destroy_read_struct(&png_pointer, &infoPointer, NULL);

  return CreateFromData(width, height, data.get(), kU8rgba);
}

void Texture::Bind() const
{
  glBindTexture(GL_TEXTURE_2D, handle_);
}

} // namespace blasted_city
