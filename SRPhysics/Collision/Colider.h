#ifndef SRPHYSICS_COLIDER_H
#define SRPHYSICS_COLIDER_H

namespace SR
{
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
                virtual bool  Intersect(const Colider& colider ) = 0;
                virtual void  Transform(const Vector3& translation) =0;
                ColiderType   GetType(){ return m_type;}
                
	};
}
#endif
