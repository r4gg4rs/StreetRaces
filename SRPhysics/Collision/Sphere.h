#ifndef SRPHYSICS_SPHERE_H
#define SRPHYSICS_SPHERE_H

namespace SR
{
  class Sphere
  {
    private:
      Vector3   m_origin;
      Real      m_radius;
    public:
      Sohere() { m_type = SPHERE;}
      Sphere(const Vector3& origin, Real radius) : m_origin(origin), m_radius(radius){ m_type =SPHERE;}
      
      Vector3&  GetPosition(){ return m_origin; }
      Real      GetRadius() {return m_radius; }
      
      bool Intersect(const Colider& colider)
      {
        switch(ColiderType)
        {
          case SPHERE:
            break;    
        }
        
        return false;
      }
      
      bool PointInside(const Vector3& point)
      {
        if(Vector3::Distance( m_origin, point) > m_radius) return false;
        return true;
      }
      
      void Transform(const Vector3& transform)
      {
        
      }
  };
}
#endif