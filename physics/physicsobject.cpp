#include "physicsobject.h"

PhysicsObject::PhysicsObject()
{

}

PhysicsObject::~PhysicsObject()
{

}

Body* PhysicsObject::GetBody()
{
	return p_body;
}

Aabb& PhysicsObject::GetBounding()
{
	return m_aabb;
}
