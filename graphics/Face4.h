#ifndef SR_FACE4_H
#define SR_FACE4_H

#include "../core/base.inc"
#include "../math/math.inc"
typedef float Real;

namespace SR
{
  class Face4
  {
    public:
      Real _a, _b,_c,_d;
    public:
      Face4(Real a, Real b, Real c, Real d):_a(a),_b(b),_c(c),_d(d) {}
      ~Face4(){}
      void AddToIndices(std::vector<unsigned int>& indices)
      {
        indices.push_back(_a);
        indices.push_back(_b);
        indices.push_back(_c);
        
        indices.push_back(_c);
        indices.push_back(_d);
        indices.push_back(_a);
      }
 };
}
#endif
