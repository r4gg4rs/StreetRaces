#include "body.h"
#include <iostream>
Body::Body()
{
}

Body::~Body()
{

}

void Body::SetPosition(const Vector3& position)
{
  m_position = position;
}

const Vector3& Body::GetPosition() const
{
  return m_position;
}

void Body::SetVelocity(const Vector3& velocity)
{
  m_velocity = velocity;
}

void Body::AddVelocity(const Vector3& velocity)
{
  m_velocity += velocity;
}

const Vector3& Body::GetVelocity() const
{
  return m_velocity;
}


void Body::SetAcceleration(const Vector3& acceleration)
{
  m_acceleration = acceleration;
}

void Body::AddAcceleration(const Vector3& acceleration)
{
  m_acceleration += acceleration;
}

const Vector3& Body::GetAcceleration() const
{
  return m_acceleration;
}

void Body::SetTotalForce(const Vector3& force)
{
  m_force = force;
}

void Body::AddForce(const Vector3& force)
{
  m_force += force;
}

const Vector3& Body::GetForce() const 
{
  return m_force;
}

void Body::ClearForce()
{
	m_force = Vector3(0.0f,0.0f,0.0f);
}
void Body::SetMass(real mass)
{
  m_inverseMass = 1 /mass;
}

real Body::GetMass() const
{
  return 1/m_inverseMass;
}

void Body::SetInverseMass(real inverseMass)
{
  m_inverseMass = inverseMass;
}

real Body::GetInverseMass() const
{
  return m_inverseMass;
}

void Body::Simulate(real dt)
{
	m_acceleration = m_force * m_inverseMass;
	m_velocity += m_acceleration;
	m_position += m_velocity;
	ClearForce();
}



void Body::Print()
{
	
}
