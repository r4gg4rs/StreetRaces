#ifndef SR_COMPONENTS_BODY_COMPONENT_H
#define SR_COMPONENTS_BODY_COMPONENT_H

#include "../core/Component.h"

namespace SR
{
	class BodyComponent : public Component
	{
		public:
			BodyComponent();
			~BodyComponent();
		
		private:
		  Real      m_inverseMass;
		  Vector3   m_velocity;
		  Vector3   m_acceleration;
		  Vector3   m_forces;
		  
		  void SetMass(Real mass)
		  {
		    m_inverseMass = 1 / mass;
		  }
		  
		  
		  void AddMass(Real mass)
		  {
		    Real current = 1 / mass;
		    m_inverseMass = 1 / current + mass;
		  }
		  
		  
		  Mass GetMass() const
		  {
		    return 1 / m_inverseMass;
		  }
		  
		  
		  void SetAcceleration(const Vector3& acc)
		  {
		    m_acceleration = acc;
		  }
		  
		  
		  void AddAcceleration(const Vector3& acc)
		  {
		    m_acceleration += acc;
		  }
		  
		  
		  Vector3& GetAcceleration()
		  {
		    return m_acceleration;
		  }
		  
		  
		  void SetVelocity(const Vector3& vel)
		  {
		    m_velocity = vel;  
		  }
		  
		  
		  void AddVelocity(const Vector3& vel)
		  {
		    m_velocity += vel;
		  }
		  
		  
		  Vector3& GetVelocity()
		  {
		    return m_velocity;
		  }
		  
		  
		  void SetForce(const Vector3& force)
		  {
		    m_forces = force;
		  }
		  
		  
		  void AddForce(const Vector& force)
		  {
		    m_forces += force;
		  }
		  
		  
		  Vector3& GetForce()
		  {
		    return m_forces;
		  }
	};
}
#endif
