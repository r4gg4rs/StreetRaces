#ifndef SR_VECTOR2_H
#define SR_VECTOR2_H

#include <cmath>


namespace SR
{
  class Vector2
  {
    public:
      Real x,y;
      
    public:
      Vector2():x(0.0), y(0.0){}
      Vector2(Real _x, Real _y) :x(_x),y(_y){}
      ~Vector2(){}
      
      void operator = (const Vector2& vec)
      {
        x = vec.x;
        y = vec.y;
      }
      
      
      Vector2 operator +(const Vector2& vec)
      {
        return Vector2(x + vec.x, y + vec.y);
      }
      
      
      Vector2 operator -(const Vector2& vec)
      {
        return Vector2( x - vec.x, y - vec.y);
      }
      
      
      Vector2 operator *(Real scalar)
      {
        return Vector2( x * scalar, y * scalar);
      }
      
      Vector2& operator += (const Vector2& vec)
      {
        x += vec.x;
        y +=vec.y;
        return *this;
      }
      
  };
}
#endif