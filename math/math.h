#ifndef STREETRACER_MATH_H
#define STREETRACER_MATH_H

#include <cmath>

namespace SR
{
	namespace Math
	{
		float Abs(float val)
		{
			if( val > 0 ) return val;
			return -val;
		}
		
		
		float RadToDeg(float rad)
		{
			 return 180 / M_PI * rad;
		}
		
		
		float DegToRad(float deg)
		{
			 return deg * M_PI / 180;
		}
		
		
		void SinCos(float& sin, float& cos,float ang)
		{
			sinv = sin(ang);
   		cosv = cos(ang);
		}
	}	
}
#endif
