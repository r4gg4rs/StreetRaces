#ifndef SR_PHYSICS_BODY_H
#define SR_PHYSICS_BODY_H

#include "../core/MeshObject.h"
#include <memory>
#include "../math/vec.h"

namespace SR
{
 // namespace Physics
  //{
  /*
  	struct Vector3
  	{
  	public:
  		Real x;
  		Real y;
  		Real z;
  		
  		void operator +=( const Vector3& vec) 
  		{
  			x+=x;
  			y+=y;
  			x+=z;
  		}
  	};
  */
    class Body
    {
      protected:
        Real          m_inverseMass;
        Vector3       m_acceleration;
        Vector3       m_velocity;
        Vector3       m_forces;
        
        Vector3				m_torque;
        Vector3				m_angularVelocity;
        
        MeshObjectPtr p_owner;
      public:
        Body(){}
        ~Body(){}
        
        void SetOwner(MeshObjectPtr owner)
        {
          p_owner = owner;
        }
        
        MeshObjectPtr GetOwner()
        {
          return p_owner;
        }
        
        void SetMass(Real mass)
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
        
        void SetForce( const Vector3& force)
        {
        	m_forces = force;
        }
        
        
        void AddForce( const Vector3& force)
        {
        	m_forces += force;
        }
        
        
        Vector3& GetForce()
        {
        	return m_forces;
        }
        
        void SetTorque(const Vector3& torque) 
        {
        	m_torque = torque;
        }
        
        void AddTorque(const Vector3& torque)
        {
        	m_torque += torque;
        }
        
        Vector3& GetTorque()
        {
        	return m_torque;
        }
        
        void SetAngularVelocity( const Vector3& velocity)
        {
        	m_angularVelocity = velocity;
        }
        
        void AddAngularVelocity( const Vector3& vel)
        {
        	m_angularVelocity += vel;
        }
        
        Vector3& GetAngularVelocity()
        {
        	return m_angularVelocity;
        }
    };
    
    typedef std::shared_ptr<Body> BodyPtr;
  //}
}
#endif
