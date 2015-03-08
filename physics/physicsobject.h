#ifndef SR_PHYSICSOBJECT_H
#define SR_PHYSICSOBJECT_H

class PhysicsObject
{
	public:
		PhysicsObject();
		~PhysicsObject();
		
		Body* GetBody();
		Aabb& GetBounding();
	private:
		Body* 	p_body;
		Aabb		m_aabb;
};
#endif
