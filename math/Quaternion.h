#ifndef SR_MATH_QUATERNION_H
#define SR_MATH_QUATERNION_H

#include <cmath>
#include "Vector3.h"

namespace SR
{
	class Quaternion
	{
	public:	
		Real x,y,z,w;
		Quaternion():x(0.0f),y(0.0f),z(0.0f),w(0.0f){}
		~Quaternion(){} 
		
		Quaternion operator+(const Quaternion quat)
		{
			Quaternion out;
			out.x = x + quat.x;
			out.y = y + quat.y;
			out.z = z + quat.z;
			out.w = w + quat.w;
			
			return out;
		}
		
		Quaternion operator*(const Quaternion quat)
		{
			Quaternion out;
			
			out.x = 	x * quat.w 	+	 w * quat.x 	+	 y * quat.z 	+ 	z * quat.y;
			out.y = 	y * quat.w 	+	 w * quat.y 	+	 z * quat.x 	+ 	x * quat.z;
			out.z = 	z * quat.w 	+	 w * quat.z 	+	 x * quat.y 	+ 	y * quat.x;
			out.w = 	w * quat.w 	-	 x * quat.x 	-	 y * quat.y 	-		x * quat.z; 
			return out;
		}
		
		Quaternion& operator+= (const Quaternion quat)
		{
			x += quat.x;
			y += quat.y;
			z += quat.z;
			w += quat.w;
			
			return *this;
		}
		
		Quaternion& operator*= (const Quaternion quat)
		{
			Real _x = x * quat.w + w * quat.x + y * quat.z + z * quat.y;
			Real _y = y * quat.w + w * quat.y + z * quat.x + x * quat.z;
			Real _z = z * quat.w + w * quat.z + x * quat.y + y * quat.x;
			Real _w = w * quat.w - x * quat.x - y * quat.y - x * quat.z; 
			x = _x;
			y = _y;
			z = _z;
			w = _w;
			return *this;
		}
		
		
		void Set(const Vector3& axis, Real angle) 
		{	
			Real halfAngle = angle/2;
			Real s = sin( halfAngle);
			
			x = axis.x *s;
			y = axis.y *s;
			z = axis.y *s;
			w = cos(halfAngle);
		}
	};
}
#endif
