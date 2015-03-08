#ifndef SR_MATH_FACE3_H
#define SE_MATH_FACE3_H

namspace SR
{
  typedef unsigned int Uint;
  class Face3
  {
    public:
      Uint a,b,c;
      Vector3   normal;
    public:
      Face(Uint _a, Uint _b, Uint _c): a(_a), b(_b),c(_c){}
      Face(Uint _a, Uint _b, Uint _c, const Vector3& _normal) : a(_a),b(_b),c(_c),normal(normal){}
      ~Face(){}
  }
}
#endif