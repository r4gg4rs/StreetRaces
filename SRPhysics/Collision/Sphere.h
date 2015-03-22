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
      
      bool Intersect(const Colider& colider)
      {
        switch(ColiderType)
        {
          case SPHERE:
            break;    
        }
        
        return false;
      }
      
      void Transform(const Vector3& transform)
      {
        
      }
  };
}
#endif