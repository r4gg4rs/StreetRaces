#ifndef SR_MATH_VECTOR3_H
#define SR_MATH_VECTOR3_H

#include <stdio.h>
#include <math.h>

#include <glm/glm.hpp>

namespace SR
{
	typedef float Real;
	class Vector3
	{
	public:
		Real x,y,z;

	public:
		inline Vector3(): x(0),y(0),z(0)
		{ 

		}

		inline Vector3(Real _x, Real _y, Real _z): x(_x),y(_y),z(_z)
		{

		}

		inline Vector3& operator=(const Vector3& vec) 
		{
			x = vec.x;
			y = vec.y;
			z = vec.z;

			return *this;
		}


		Vector3& operator=(const Real arr[]) 
		{
			x = arr[0];
			y = arr[1];
			z = arr[2];

			return *this;
		}


		Vector3& operator=(const Real scalar)
		{
			x = scalar;
			y = scalar;
			z = scalar;

			return *this;
		}	

		Real& operator [] ( const size_t i)
		{
			return *(&x+i);
		}
/*
		Real& operator [] (const size_t i)
		{
			return *(&x+i)
		}
*/
		Vector3 operator + ( const Vector3& vec) const
		{
			return Vector3(
				x + vec.x,
				y + vec.y,
				z + vec.z
			);
		}

		Vector3 operator - ( const Vector3& vec) const
		{
			return Vector3(
				x-vec.x,
				y-vec.y,
				z-vec.z
			);

		}

		Vector3 operator * ( const Real scalar) const
		{
			return Vector3(
						x * scalar,
						y * scalar,
						z * scalar
				 	);
		}

		Vector3 operator / ( const Real scalar) const
		{
			return Vector3(
						x / scalar,
						y / scalar,
						z / scalar
					);
		}

		Vector3& operator += (const Vector3& vec)
		{
			x += vec.x;
			y += vec.y;
			z += vec.z;
			return *this;
		}

		Vector3& operator -= (const Vector3& vec) 
		{
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
			return *this;
		}

		Vector3& operator *= (const Real scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;

			return *this;
		}

		Vector3& operator /= (const Real scalar )
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;

			return *this;
		}

		inline Real X()
		{
			return x;
		}

		inline Real Y()
		{
			return y;
		}

		inline Real Z()
		{
			return z;
		}

		inline Real Length() const
		{
			return sqrt( (x*x) +(y*y)+(z*z) );
		}

		inline void Normalize() 
		{
			Real length = Length();
			x /= length;
			y /= length;
			z /= length;	
		}
	

		inline Real DotProduct(const Vector3& vec) const
		{
			return ( x * vec.x ) + ( y * vec.y) + (z * vec.z);
		}

		inline Vector3 CrossProduct( const Vector3& vec) const
		{
			return Vector3(
						y * vec.z - z * vec.y,
						z * vec.x - x * vec.z,
						x * vec.y - y * vec.x
						);
		}

		inline Real* Ptr()
		{
			return &x;
		}

		inline const Real* Ptr() const
		{
			return &x;
		}

    inline glm::vec3 ToGglmVec()
    {
      return glm::vec3(x,y,z);
    }

		static Vector3 Zero()
		{
			return Vector3();
		}

		static Vector3 Min(const Vector3& a, const Vector3& b)
		{
			Vector3 out;
			
			if(a.x < b.x) 	out.x = a.x;
			else 			out.x = b.x;
			
			if(a.y < b.y) 	out.y = a.y; 
			else			out.y = a.y;

			if(a.z < b.z)	out.z = a.z;
			else			out.z = b.x;

			return out;
		}

		static Vector3 Max(const Vector3& a, const Vector3& b)
		{
			Vector3 out;

			if(a.x > b.x)	out.x = a.x;
			else			out.x = b.x;

			if(a.y > b.y)	out.y = a.y;
			else			out.y = b.y;

			if(a.z > b.z)	out.z = a.z;
			else			out.z = b.z;

			return out;
		}

		static Real Distance( const Vector3& a, const Vector3& b)
		{
			Vector3 dist = b - a;
			return dist.Length();
		}
	};
}
#endif
