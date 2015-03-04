#include "global.h"

#include "engine/Window.h"

#include <cstdlib>
#include <cstdio>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

namespace blasted_city {

void Terminate [[noreturn]] (const char *message)
{
  std::fprintf(stderr, "%s\n", message);
  std::fflush(stderr);
  Window::instance()->Shutdown();
  std::exit(1);
}

std::string ReadTextFile(const char *filename)
{
  struct stat stat_buffer;

  if (stat(filename, &stat_buffer) < 0) {
    auto error_msg = std::string("Failed to stat file ");

    error_msg += filename;
    Terminate(error_msg.c_str());
  }
  if (stat_buffer.st_size <= 0) {
    auto errorMsg = std::string("Size of file ");

    errorMsg += filename;
    errorMsg += " is invalid";
    Terminate(errorMsg.c_str());
  }

  std::size_t data_remaining = static_cast<size_t>(stat_buffer.st_size);
  auto data_buffer = StdLibAllocate<char>(data_remaining);

  if (!data_buffer) {
    Terminate("Out of memory");
  }

  int fd = open(filename, O_RDONLY);

  if (fd == -1) {
    auto error_msg = std::string("Failed to open file ");

    error_msg += filename;
    Terminate(error_msg.c_str());
  }

  ssize_t size_read;
  char *buffer_position = data_buffer.get();

  while (data_remaining > 0) {
    if ((size_read = read(fd, buffer_position, data_remaining)) == -1) {
      auto error_msg = std::string("Failed to read from file %s");

      error_msg += filename;
      Terminate(error_msg.c_str());
    }
    data_remaining -= static_cast<size_t>(size_read);
    buffer_position += size_read;
  }

  return std::string(data_buffer.get());
}

} // namespace blasted_city
