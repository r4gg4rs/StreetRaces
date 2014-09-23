#ifndef CHOPPER_MATH_VECTOR_ALG_H
#define CHOPPER_MATH_VECTOP_ALG_H

#include <cmath>
#include "vec.h"
#include "math.h"


namespace MATH
{
  float Lenght(const Vector3& vec);
  float Distance(const Vector3& vec1, const Vector3& vec2);
  float Dot(const Vector3& vec1, const Vector3& vec2);
  Vector3 Cross(const Vector3& vec1, const Vector3& vec2);
};
#endif
