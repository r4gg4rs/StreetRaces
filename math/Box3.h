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
      Box3(){}
      Box3(const Vector3& min, const Vector3& max): m_min(min), m_max(max) {}
      ~Box3(){}
    
      const Vector3&  GetMin() 		{	return m_min; }
      const Vector3&  GetMax() 		{ return m_max; }
      
      bool Intersect(const Box3* box)
      {
      	Vector3 b_min = box->GetMin();
      	Vector3 b_max = box->GetMax();
      	if(m_min.x > b_max.x || m_max.x < b_min.x ) return false;
      	if(m_min.y > b_max.y || m_max.y < b_min.y ) return false;
      	if(m_min.z > b_max.z || m_max.z < b_min.z ) return false;
      	
      	return true;
      }
  }
}
#endif
