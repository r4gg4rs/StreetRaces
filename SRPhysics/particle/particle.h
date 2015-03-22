#ifndef SR_PHYSICS_PARTICLE_H
#define sR_PHYSICS_PARTICLE_H

namespace SR
{
	class Particle
	{
		private:
			Vector3			m_position;
			Real				m_inverseMass;
			Vector3			m_acceleration;
			Vector3			m_velocity;
			Vector3			m_force;
			
			
		public:
			Particle(){}
			Particle(const Vectror3& pos) : m_position(pos) {}
			~Particle() {}
			
			Real GetMass()
			{
				return 1 / m_inverseMass;
			} 
			
			void SetMass( Real mass ) 
			{
				m_inverseMass = 1 /mass;
			}
			
			void AddMass( Real mass )
			{
				Real oldMass = GetMass();
				m_inverseMass = 1 / oldMass + mass;
			}
			
			Vector3& GetAcceleration()
			{
				return m_acceleration;
			}
			
			Void SetAcceleration( const Vector3& acceleration )
			{
				m_acceleration = acceleration;
			}
			
			
			void AddAcceleration( const Vector3& acc ) 
			{
				m_acceleration += acc;
			}
			
			
			Vector3& GetVelocity()
			{
				return m_velocity;
			}
			
			
			void SetVelocity( const Vector3& vel) 
			{
				m_velocity = vel;
			}
			
			void AddVelocity( const Vector3& vel)
			{
				m_velocity += vel;
			}
			
			
			Vector3& GetForce()
			{
				return m_force;			
			}
			
			
			void SetForce(const Vector3& force)
			{
				m_force = force;
			}
			
			void AddForce( const Vector3& force)
			{
				m_force += force;
			}
	};
}
#endif
