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
      Sphere(const Vector3& origin, Real radius);
      ~Sphere();
      
   }
 }
 #endif