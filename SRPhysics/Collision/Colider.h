#ifndef SRPHYSICS_COLIDER_H
#define SRPHYSICS_COLIDER_H

namespace SR
{
  
  struct CollisionData
  {
    BodyPtr   body[2];
    Vector3   point;
    Vector3   normal;
    Real      penetration;
    bool      intersect;
  };
  
	class Colider
	{
            public:
                enum ColiderType
                {
                    SPHERE,
                    AABB
                };
            private:
                ColiderType     m_type;
            public:
                virtual CollisionData  Intersect(const Colider& colider ) = 0;
                virtual void  Transform(const Vector3& translation) =0;
                ColiderType   GetType(){ return m_type;}
                
	};
}
#endif
