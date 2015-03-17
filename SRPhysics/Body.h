#ifndef SR_PHYSICS_BODY_H
#define SR_PHYSICS_BODY_H

#include "../core/MeshObject.h"
#include <memory>

namespace SR
{
  namespace Physics
  {
    class Body
    {
      protected:
        Real          m_inverseMass;
        Vector3       m_acceleration;
        Vector3       m_velocity;
        Vector3       m_forces;
        MeshObjectPtr p_owner;
      public:
        Body(){}
        ~Body(){}
        
        void SetOwner(MeshObject* owner)
        {
          p_owner = owner;
        }
        
        MeshObjectPtr GetOwner()
        {
          return p_owner;
        }
        
        void SetMass(real mass)
        {
          m_inverseMass = 1 / mass;
        }
        
        void AddMass(Real mass)
        {
          Real newMass = GetMass() +mass;
          m_inverseMass = 1/newMass;
        }
        
        Real GetMass() const
        {
          return 1 / m_inverseMass;
        }
        
        void SetInverseMass( Real inverseMass)
        {
          m_inverseMass = inverseMass;
        }
        
        Real GetInverseMass() const
        {
          return m_inverseMass;
        }
    };
    
    typedef std::shared_ptr<Body> BodyPtr;
  }
}
#endif