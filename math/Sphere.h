/**
 * @author    Jani Haippo
 * @version   03.2015
 * 
 * Bounding Sphere 3
 * */
 
 #ifndef SR_SPHERE_H
 #define SR_SPHERE_H
 
 namespace SR
 {
   class Sphere
   {
     private:
      Vector3     m_origin;
      Real        m_radius;
     public:
      Sphere(const Vector3& origin, Real radius) : m_origin(origin), m_radius(radius) {}
      ~Sphere(){}
      
      Vector3		GetPosition() { return m_origin; }
      Real			GetRadius() 	{ return m_radius; }
      
      
      bool Intersect(const Sphere* sphere) 
      {
      	if(m_radius + sphere.GetRadius() < Vector::Distance( m_origin, sphere->GetPosition() ) return false;
      	return true;
      }
      
   }
 }
 #endif
