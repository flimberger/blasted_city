#ifndef BLASTED_CITY_GLOBAL_H_
#define BLASTED_CITY_GLOBAL_H_

#include <sys/types.h>

#include <cstdlib>
#include <memory>
#include <string>

namespace blasted_city {

// temporarily globals
constexpr auto kBulletName        = "bullet";
constexpr auto kProtoSoldierName  = "protoSoldier";

void Terminate [[noreturn]] (const std::string &message);

template<typename T>
class StdLibDeleter {
 public:
  void operator()(T *pointer) const noexcept;
};

template<typename T>
void StdLibDeleter<T>::operator()(T *pointer) const noexcept
{
  if (pointer) {
    std::free(pointer);
  }
}

template<typename T>
using StdUniquePtr = std::unique_ptr<T, StdLibDeleter<T>>;

template<typename T>
StdUniquePtr<T> StdLibAllocate(std::size_t count) noexcept
{
  auto pointer = StdUniquePtr<T>(reinterpret_cast<T *>(std::calloc(count, sizeof(T))));

  if (!pointer) {
    Terminate("Out of memory");
  }

  return pointer;
}

std::string ReadTextFile(const std::string &filename);

} // namespace blasted_city

#endif // BLASTED_CITY_GLOBAL_H_
