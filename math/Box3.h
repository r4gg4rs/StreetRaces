/**
 * @author    Jani Haippo
 * @version   03.2015
 * 
 * BoundingBox 3d
 * */

#ifndef SR_BOX_H
#define SR_BOX_H

namespace SR
{
  class Box3
  {
    private:
      Vector3     m_min;
      Vector3     m_max;
    public:
      Box3();
      Box3(const Vector3& min, const Vector3& max);
      ~Box3();
    
      const Vector3&  GetMin();
      const Vector3&  GetMax();
  }
}
#endif