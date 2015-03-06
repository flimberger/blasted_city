#include "global.h"

#include "engine/Window.h"

#include <cstdlib>
#include <cstdio>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

namespace blasted_city {

void Terminate [[noreturn]] (const std::string &message)
{
    std::fprintf(stderr, "%s\n", message.c_str());
    std::fflush(stderr);
    std::exit(1);
}

std::string ReadTextFile(const std::string &filename)
{
  struct stat stat_buffer;

  if (stat(filename.c_str(), &stat_buffer) < 0) {
    Terminate("Failed to stat file " + filename);
  }
  if (stat_buffer.st_size <= 0) {
    Terminate("Size of file " + filename + " is invalid");
  }

  std::size_t data_remaining = static_cast<size_t>(stat_buffer.st_size);
  auto data_buffer = StdLibAllocate<char>(data_remaining);

  if (!data_buffer) {
    Terminate("Out of memory");
  }

  int fd = open(filename.c_str(), O_RDONLY);

  if (fd == -1) {
    Terminate("Failed to open file " + filename);
  }

  ssize_t size_read;
  char *buffer_position = data_buffer.get();

  while (data_remaining > 0) {
    if ((size_read = read(fd, buffer_position, data_remaining)) == -1) {
      Terminate("Failed to read from file" + filename);
    }
    data_remaining -= static_cast<size_t>(size_read);
    buffer_position += size_read;
  }

  return std::string(data_buffer.get());
}

} // namespace blasted_city
