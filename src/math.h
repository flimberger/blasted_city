#ifndef BLASTED_CITY_MATH_H_
#define BLASTED_CITY_MATH_H_

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include <cmath>

namespace blasted_city {

constexpr auto kPi  = float(M_PI);
constexpr auto kPi2 = kPi * 0.5f;

using Vec2 = glm::vec2;
using Vec3 = glm::vec3;

} // namespace blasted_city

#endif // BLASTED_CITY_MATH_H_
