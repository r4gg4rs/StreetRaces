#ifndef SR_MATRIX4_H
#define SR_MATRIX4_H


#define GLM_FORCE_RADIANS 

#include <stdio.h>		
#include <math.h>
#include "Vector3.h"
#include "Quaternion.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
#include <iostream>

typedef float Real;
/**
 * m0   m4    m8    m12   
 * m1   m5    m9    m13   
 * m2   m6    m10   m14   
 * m3   m7    m11   m15
 * **/
namespace SR
{
	class Matrix4
	{
	public:
		Matrix4()
		{
			m_data[0] = 1.0f;	m_data[4] = 0.0f;	m_data[8] = 0.0f;	m_data[12] = 0.0f;
			m_data[1] = 0.0f;	m_data[5] = 1.0f; 	m_data[9] = 0.0f;	m_data[13] = 0.0f;
			m_data[2] = 0.0f;	m_data[6] = 0.0f;	m_data[10] = 1.0f;	m_data[14] = 0.0f;
			m_data[3] = 0.0f; 	m_data[7] = 0.0f;	m_data[11] = 0.0f;	m_data[15] = 0.0f;
		}

		Matrix4( 	Real m11, Real m12, Real m13, Real m14, 
					Real m21, Real m22, Real m23, Real m24, 
					Real m31, Real m32, Real m33, Real m34, 
						Real m41, Real m42, Real m43, Real m44)
		{
			m_data[0] = m11; 	m_data[4] = m12;	m_data[8] = m13;	m_data[12] = m14;
			m_data[1] = m21;	m_data[5] = m22;	m_data[9] = m23;	m_data[13] = m24;
			m_data[2] = m31;	m_data[6] = m32;	m_data[10] = m33;	m_data[14] = m34;
			m_data[3] = m41;	m_data[7] = m42;	m_data[11] = m43;	m_data[15] = m44;

		}

		~Matrix4(){}
		void operator =(const glm::mat4& mat)
		{
		  m_data[0] = mat[0][0]; m_data[4] = mat[1][0]; m_data[8]  = mat[2][0]; m_data[12] = mat[3][0];
		  m_data[1] = mat[0][1]; m_data[5] = mat[1][1]; m_data[9]  = mat[2][1]; m_data[13] = mat[3][1];
		  m_data[2] = mat[0][2]; m_data[6] = mat[1][2]; m_data[10] = mat[2][2]; m_data[14] = mat[3][2];
  	  m_data[3] = mat[0][3]; m_data[7] = mat[1][3]; m_data[11] = mat[2][3]; m_data[15] = mat[3][3];
		}
		Real& operator [] (const size_t i)
		{
			return m_data[i];
		}
			
		
		Real& operator()(const size_t col, const size_t row)
		{
		  return m_data[row*4 + col];
		}
/*
		Matrix4& operator = (const Matrix4& mat)
		{
			return *this;
		}	
*/
		Matrix4 operator + (Matrix4 mat)
		{
			return Matrix4(	m_data[0] + mat[0],	m_data[4] + mat[4],	m_data[8] + mat[8],	m_data[12] + mat[12],
							m_data[1] + mat[1], m_data[5] + mat[5], m_data[9] + mat[9], m_data[13] + mat[13],
							m_data[2] + mat[2], m_data[6] + mat[6], m_data[10] + mat[10], m_data[14] + mat[14],
							m_data[3] + mat[3], m_data[7] + mat[7], m_data[11] + mat[11], m_data[15] + mat[15]
							);
		}

		Matrix4 operator * ( Matrix4 mat)
		{
			Matrix4 out;
		
			//out[0]
			out[0]  = m_data[0] * mat[0]  + m_data[4] * mat[1]  + m_data[8]  * mat[2]  + m_data[12] * mat[3];
			//out[1]  
			out[4]  = m_data[0] * mat[4]  + m_data[4] * mat[5]  + m_data[8]  * mat[6]  + m_data[12] * mat[7];	
			//out[2]  
			out[8]  = m_data[0] * mat[8]  + m_data[4] * mat[9]  + m_data[8]  * mat[10] + m_data[12] * mat[11];
			//out[3]  
			out[12] = m_data[0] * mat[12] + m_data[4] * mat[13] + m_data[8]  * mat[14] + m_data[12] * mat[15];
		
			//out[4]  
			out[1]  = m_data[1] * mat[0]  + m_data[5] * mat[1]  + m_data[9]  * mat[2]  + m_data[13] * mat[3];
			//out[5]  
			out[5]  = m_data[1] * mat[4]  + m_data[5] * mat[5]  + m_data[9]  * mat[6]  + m_data[13] * mat[7];
			//out[6]  
			out[9]  = m_data[1] * mat[8]  + m_data[5] * mat[9]  + m_data[9]  * mat[10] + m_data[13] * mat[11];
			//out[7]  
			out[13] = m_data[1] * mat[12] + m_data[5] * mat[13] + m_data[9]  * mat[14] + m_data[13] * mat[15];

			//out[8]  
			out[2]  = m_data[2] * mat[0]  + m_data[6] * mat[1]  + m_data[10] * mat[2]  + m_data[14] * mat[3]; 
			//out[9]  
			out[6] = m_data[2] * mat[4]  + m_data[6] * mat[5]  + m_data[10] * mat[6]  + m_data[14] * mat[7];
			//out[10] 
			out[10] = m_data[2] * mat[8]  + m_data[6] * mat[9]  + m_data[10] * mat[10] + m_data[14] * mat[11];
			//out[11] 
			out[14]  = m_data[2] * mat[12] + m_data[6] * mat[13] + m_data[10] * mat[14] + m_data[14] * mat[15];
		
			//out[12] 
			out[3]  = m_data[3] * mat[0]  + m_data[7] * mat[1]  + m_data[11] * mat[2]  + m_data[15] * mat[3];
			//out[13] 
			out[7]  = m_data[3] * mat[4]  + m_data[7] * mat[5]  + m_data[11] * mat[6]  + m_data[15] * mat[7];
			//out[14] 
			out[11] = m_data[3] * mat[8]  + m_data[7] * mat[9]  + m_data[11] * mat[10] + m_data[15] * mat[11];
			//out[15] 
			out[15] = m_data[3] * mat[12] + m_data[7] * mat[13] + m_data[11] * mat[14] + m_data[15] * mat[15];
				
			return out;
		}
		
		
		
		/*
		  multiply by vector
		*/
		Vector3 operator * (const Vector3& v)
		{
		  Real fInvW = 1.0 / (m_data[12] * v.x + m_data[13] * v.y + m_data[14] * v.z +m_data[15]);
		  
		  return  Vector3 (
		    (m_data[0] * v.x  +   m_data[4] * v.y +   m_data[8] * v.z +   m_data[12]) * fInvW,
		    (m_data[1] * v.x  +   m_data[5] * v.y +   m_data[9] * v.z +   m_data[13]) * fInvW,
		    (m_data[2] * v.x  +   m_data[6] * v.y +   m_data[10]* v.z +   m_data[14]) * fInvW
		    );
		}
		
		
    inline void Set(	Real m11, Real m12, Real m13, Real m14, 
					Real m21, Real m22, Real m23, Real m24, 
					Real m31, Real m32, Real m33, Real m34, 
						Real m41, Real m42, Real m43, Real m44)
		{
			m_data[0] = m11; 	m_data[4] = m12;	m_data[8] = m13;	m_data[12] = m14;
			m_data[1] = m21;	m_data[5] = m22;	m_data[9] = m23;	m_data[13] = m24;
			m_data[2] = m31;	m_data[6] = m32;	m_data[10] = m33;	m_data[14] = m34;
			m_data[3] = m41;	m_data[7] = m42;	m_data[11] = m43;	m_data[15] = m44;

		}
		
		
		void MakeTranslation(const Vector3& trans)
		{
		  Set(  1.0f, 0.0f, 0.0f, trans.x,
		        0.0f, 1.0f, 0.0f, trans.y,
		        0.0f, 0.0f, 1.0f, trans.z,
		        0.0f, 0.0f, 0.0f, 1.0f
		  );
		}
		
		
		void MakeRotationX(Real angle) 
		{
		  Real _sin = sin(angle);
		  Real _cos = cos(angle);
		  Set(  1.0f,   0.0f,   0.0f,   0.0f,
		        0.0f,   _cos,   -_sin,  0.0f,
		        0.0f,   _sin,   _cos,   0.0f,
		        0.0f,   0.0f,   0.0f,   1.0f
		  );
		}
		
		void MakeRotationY(Real angle) 
		{
		  Real _sin = sin(angle);
		  Real _cos = cos(angle);
		
		  Set(  _cos,   0.0f,   _sin,   0.0f,
		        0.0f,   1.0f,   0.0f,   0.0f,
		        -_sin,  0.0f,   _cos,   0.0f,
		        0.0f,   0.0f,   0.0f,   1.0f
      );
		}
		
		
		void MakeRotationZ(Real angle)
		{
		  Real _sin = sin(angle);
		  Real _cos = cos(angle);
		  
		  Set(  _cos, -_sin,  0.0f, 0.0f,
		        _sin, -_cos,   0.0f, 0.0f,
		        0.0f, 0.0f,   1.0f, 0.0f,
		        0.0f, 0.0f,   0.0f, 1.0f
      );
		}
		
		void MakeRotation(const Vector3& axis, Real angle)
		{
		  
		}
		
		
		void MakeRotation( const Quaternion& rotation)
		{
			Real x = rotation.x;
			Real y = rotation.y;
			Real z = rotation.z;
			Real w = rotation.w;
		
		  Real xx, xy, xz, yy, yz, zz, wx, wy, wz;
		  
		  xx = x * x * 2.0;
		  xy = x * y * 2.0;
		  xz = x * z * 2.0;
		  
		  yy = y * y * 2.0;
		  yz = y * z * 2.0;
		  
		  zz = z * z * 2.0;
		  
		  wx = w * x * 2.0;
		  wy = w * y * 2.0;
		  wz = w * z * 2.0;
		  
		  
		  m_data[0] = 1.0 -(yy+zz);		m_data[4] = xy - wz;			m_data[8]  = xz + wy;				m_data[12] = 0.0;
			m_data[1] = yz + wz;				m_data[5] = 1.0-( xx+zz);	m_data[9]  = yz - wx;				m_data[13] = 0.0;
			m_data[2] = xz - wy;				m_data[6] = yz + wx;			m_data[10] = 1 -( xx+yy );	m_data[14] = 0.0;
			m_data[3] =	0.0;						m_data[7] = 0.0;					m_data[11] = 0.0;						m_data[15] = 1.0;
		
/*
		  m_data[0] = 1.0 -(yy+zz);		m_data[1] = xy + wz;			m_data[2]  = xz + wy;				m_data[3] = 0.0;
			m_data[4] = yz - wz;				m_data[5] = 1 -( xx+zz);	m_data[6]  = yz - wx;				m_data[7] = 0.0;
			m_data[8] = xz - wy;				m_data[9] = yz + wx;			m_data[10] = 1 -( xx+yy );	m_data[11] = 0.0;
			m_data[12] =	0.0;					m_data[13] = 0.0;					m_data[14] = 0.0;						m_data[15] = 1.0;
*/
		}
		
		void MakeScale(const Vector3& scale)
		{
		  Set(  scale.x,  0.0f,     0.0f,     0.0f,
		        0.0f,     scale.y,  0.0f,     0.0f,
		        0.0f,     0.0f,     scale.z,  0.0f,
		        0.f,      0.0f,     0.0f,     1.0f
		  );
		}
		
		void MakeScale(Real scalar)
		{
		  Set(  scalar, 0.0f,   0.0f,   0.0f,
		        0.0f,   scalar, 0.0f,   0.0f,
		        0.0f,   0.0f,   scalar, 0.0f,
		        0.0f,   0.0f,   0.0f,   1.0f
		  );
		}
		
		void MakePerspective(Real fov, Real aspect, Real near, Real far)
		{
		    
     // this = glm::perspective(fov,aspect,near,far);
		  Real f  = 1.0f / tan(fov/2);
    
		  Set(  f/aspect, 0.0f,   0.0f,                   0.0f,
		        0.0f,     f,      0.0f,                   0.0f,
		        0.0f,     0.0f,   -(far+near)/(near-far), 2*far*near / (near-far),
		        0.0f,     0.0f,   0.0f,                   1.0f
		  );
		  
		}
		
		void MakeFrustum(Real left, Real right, Real bottom, Real top, Real near, Real far)
		{
	/*
		  std::cout << "test " << (right/left) / (right-left) << std::endl;
		  std::cout << "left " << left << " right "<< right << std::endl;
		  std::cout << " right/left / right -left"<<std::endl;
		  std::cout << "top "<< top << std::endl;
		  std::cout << "right" << right << std::endl;
		*/
		
		Real rlMiinus = right -left;
		Real trMiinus = top -right;
		
		if(rlMiinus == 0) rlMiinus = 0.0001;
		if(trMiinus == 0) trMiinus = 0.0001;
		  
		  Set(  (2*near)/(right -left), 0.0f,                     (right + left) / rlMiinus, 0.0f,
		        0.0f,                   (2* near) /(top-bottom),  (top+right) / trMiinus,      0.0f,
		        0.0f,                   0.0f,                     (far+near) / (far-near),        2*far*near/(far-near),
		        0.0f,                   0.0f,                     -1.0f,                          0.0f
		  );
		}
		
		void MakeFrustum(Real fov, Real aspect, Real near, Real far)
		{
		  Real yMax = near * tan(fov * 0.5 * 3.14/180);
		  Real yMin = - yMax;
		  Real xMin = yMin * aspect;
		  Real xMax = yMax * aspect;
		  
		  MakeFrustum(xMin,xMax,yMin,yMax,near,far);
		}
		
		inline const Real* Ptr() const 
		{
			return &m_data[0];
		}

		inline Real* Ptr()
		{
			return &m_data[0];
		}

		inline void Identity() 
		{
			m_data[0] = 1.0f;	m_data[4] = 0.0f;	m_data[8] = 0.0f;	m_data[12] = 0.0f;
			m_data[1] = 0.0f;	m_data[5] = 1.0f; 	m_data[9] = 0.0f;	m_data[13] = 0.0f;
			m_data[2] = 0.0f;	m_data[6] = 0.0f;	m_data[10] = 1.0f;	m_data[14] = 0.0f;
			m_data[3] = 0.0f; 	m_data[7] = 0.0f;	m_data[11] = 0.0f;	m_data[15] = 0.0f;			
		}
		
		
		Matrix4 GetTransponse()
		{
			Matrix4 out( m_data[0], m_data[1], m_data[2], m_data[3],
											m_data[4], m_data[5], m_data[6], m_data[7],
											m_data[8], m_data[9], m_data[10], m_data[11],
											m_data[12], m_data[13],m_data[14],m_data[15]);	
			return out;
		}
		
		
		
		
    void Print() 
    { std::cout << "Matrix\n\n"<<std::endl;
      std::cout << "\t"<< m_data[0] <<"\t"<< m_data[4] <<"\t"<<m_data[8] <<"\t"<< m_data[12] << std::endl;
      std::cout << "\t"<< m_data[1] <<"\t"<< m_data[5] <<"\t"<<m_data[9] <<"\t"<< m_data[13] << std::endl;
      std::cout << "\t"<< m_data[2] <<"\t"<< m_data[6] <<"\t"<<m_data[10] <<"\t"<< m_data[14] << std::endl;
      std::cout << "\t"<< m_data[3] <<"\t"<< m_data[7] <<"\t"<<m_data[11] <<"\t"<< m_data[15] << std::endl;
      
     std::cout <<"\n\n"<<std::endl;
    }
	private:
		float	m_data[16];
	};
}

#endif
