#include "vec_alg.h"

namespace MATH
{
  float Lenght(const Vector3& vec)
  {
    return sqrt(( vec.x* vec.x) + ( vec.y * vec.y) + ( vec.z * vec.z));
  } 

  float Distance(const Vector3& vec1, const Vector3& vec2)
  {
    Vector3 v = vec2 - vec1;
    return Lenght(v);
  }

  float Dot(const Vector3& vec1, const Vector3& vec2)
  {
    return ( vec1.x * vec2.y ) + ( vec1.y * vec2.y ) + ( vec1.z * vec2.z ); 
  }


  Vector3 Cross(const Vector3& vec1, const Vector3& vec2)
  {
    Vector3 temp;
    temp.x = (vec1.y * vec2.z) - ( vec1.z - vec2.y);
    temp.y = (vec1.z * vec2.x) - ( vec1.x - vec2.z);
    temp.z = (vec1.x * vec2.y) - ( vec1.y - vec2.x);
    

    return temp;
  }

};
