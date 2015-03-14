#ifndef SR_FRUSTUM_H
#define SR_FRUSTUM_H

namespace SR
{
  class Frustum
  {
    public:
      Frustum();
      ~Frustm();
     // void AddPlane( const Plane& plane);
     
     void Update(const Matrix4& matrix);
    private:
      Plane m_planes[6]; 
  };
}
#endif