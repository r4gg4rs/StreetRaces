#ifndef SR_RAY_H
#define SR_RAY_H

namespace SR
{
  class Ray
  {
    private:
      Vector3     m_origin;
      Vector3     m_direction;
      Real        m_max;
    public:
      Ray(){}
      /**
       * if max is < 0  no limit
      **/
      Ray(const Vector3& origin, const Vector3 direction, Real max=-1): 
      m_origin(origin), m_direction(direction), m_max(max)
      {
        
      }
      
      void SetOrigin(const Vector3& origin)
      {
        m_origin = origin;
      }
      
      Vector3& GetOrigin()
      {
        return m_origin;
      }
      
      void SetDirection(const Vector3& dir)
      {
        m_direction =dir;
      }
      
      Vector3& GetDirection()
      {
        return m_direction;
      }
      
      void SetMax(Real max)
      {
        m_max =max;
      }
      
      Real GetMax()
      {
        return m_max;
      }
  }
}
#endif