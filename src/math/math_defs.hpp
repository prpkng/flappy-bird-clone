#pragma once

#include "core/defines.hpp"

#include <limits>

namespace Math {

inline constexpr float SQRT2 = 1.4142135623730950488016887242f;
inline constexpr float SQRT3 = 1.7320508075688772935274463415059f;
inline constexpr float SQRT12 = 0.7071067811865475244008443621048490f;
inline constexpr float SQRT13 = 0.57735026918962576450914878050196f;
inline constexpr float LN2 = 0.6931471805599453094172321215f;
inline constexpr float TAU = 6.2831853071795864769252867666f;
inline constexpr float PI = 3.1415926535897932384626433833f;
inline constexpr float E = 2.7182818284590452353602874714f;
inline constexpr float INF = std::numeric_limits<float>::infinity();
inline constexpr float NaN = std::numeric_limits<float>::quiet_NaN();

}


#define CMP_EPSILON 0.00001
#define CMP_EPSILON2 (CMP_EPSILON * CMP_EPSILON)

#define UNIT_EPSILON 0.001