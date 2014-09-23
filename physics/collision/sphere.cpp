#include "sphere.h"

Sphere::Sphere()
{

}

Sphere::~Sphere()
{

}


void Sphre::SetPosition(const Vector3& position)
{
  m_position = position;
}

const Vector3& Sphere::GetPosition() const
{
  return m_position;
}

void Sphere::SetRadius(float radius)
{
  m_radius = radius;
}

float Sphere::GetRadius() const
{
  return m_radius;
}
