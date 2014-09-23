#include "math.h"

namespace MATH
{
  float RadToDeg(float rad)
  {
    return 180 / M_PI * rad;
  }

  float DegToRad(float deg)
  {
    return deg * M_PI / 180;
  }

  void SinCos(float &sinv, float &cosv,float ang)
  {
    sinv = sin(ang);
    cosv = cos(ang);
  }
}
