#ifndef SR_VECTOR3_H
#define SR_VECTOR3_H

namespace SR
{
  class Vector4
  {
    public:
      Real x;
      Real y;
      Real z;
      Real w;
    public:
      Vector4() {}
      Vector4(Real _x, Real _y, Real _z, Real _w) : x(_x), y(_y), z(_z),w(_w){}
      ~Vector4(){ }
      
    Vector4 operator +( const Vector4& vec)
    {
      return Vector4(x+vec.x, y + vec.y, vec.z + z, vec.w + w);
    }
    
    Vector4 operator -( const Vector4& vec)
    {
      return Vector4(x -vec.x, y -vec.y, z -vec.z, w - vec.w);
    }
      
    void  operator +=(const Vector4& vec)
    {
      x += vec.x;
      y += vec.y;
      z += vec.z;
      w += vec.w;
    }
    
    

  };
}
#endif