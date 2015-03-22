#ifndef SR_MATH_HELPER_H
#define SR_MATH_HELPER_H

#include <cmath>
#include "vec.h"

namespace SR
{
	class MathHelper
	{
		static Real Length(const Vector3& v ) 
		{
			return sqrt( (v.x * v.x) + ( v.y * v.y ) + ( v.z * v.z ) );
		}
		
		
		static Real Distance(const Vector3& a const Vector3& b)
		{
			return Length( b - a );
		}
		
		static Real Dot( const Vector3&a, const Vector3&b ) 
		{
			return (a.x*b.x) + (a.y*b.y) + (a.z*b.z);
		}
		
		static Vector3 Cross( const Vector3& a, const Vector3& b ) 
		{
			return Vector3(
					a.y * b.z - a.z * b.y,
					a.z * b.x - a.x * b.z,
					a.x * b.y - a.y * b.x
			);
		}
		
		static bool PointDistanceToLine( const Line& line, const Vector3& point )
		{
			Vector3 w = point - line.origin;
			Vector3 v = line.origin + line.direction;
			Vector3 w2 = MathHelper.Dot( w ,v) * v;
			return sqrt( (w * w ) - ( w2 * w2 ) );
		}
		
	};
}
#endif
