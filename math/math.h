#ifndef STREETRACER_MATH_H
#define STREETRACER_MATH_H

#include <cmath>

namespace MATH
{
	float Abs(float val);
  float RadToDeg(float rad);
  float DegToRad(float deg);
  void SinCos(float& sin, float& cos,float ang);
}
#endif
