#include "math.h"

namespace MATH
{
	float Abs(float val)
	{
		if( val < 0) return -val;
		return val;
	}

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
