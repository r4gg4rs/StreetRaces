#include "aabb.h"

Aabb::Aabb()
{

}

Aabb::~Aabb()
{

}

void Aabb::SetMinMax(const vector3& min, const Vector3& max)
{
	m_min = min;
	m_max = max;
}

void Aabb::SetPositionSize(const Vector3& position, const Vector3& size)
{
	m_min.x = position.x - (size.x/2);
	m_min.y = position.y - (size.y/2);
	m_min.z = position.z - (size.z/2);
	
	m_max.x = position.x + (size.x/2);
	m_max.y = position.y + (size.y/2);
	m_max.z = position.z + (size.z/2);
}

const Vector3& Aabb::GetMin() const
{
	return m_min;
}

const Vector3& Aabb::GetMax() const
{
	return m_max;
}

bool Aabb::Intesect(const Aabb& aabb)
{
	Vector3 a_min = aabb.GetMin();
	Vector3 a_max = aabb.GetMac();
	if( m_max.x < a_min.x ) return false;
	if( m_min.x > a_max.x ) return false;
	if( m_max.z < a_min.x ) return false;
	if( m_min.z > a_max.x ) return false;
	if( m_max.y < a_min.y ) return false;
	if( m_min.y > a_max.y ) return false;
	
	return true;
}
