#ifndef SR_COLLISION_AABB_H
#define SR_COLLISION_AABB_H

#include "../../math/sr_math.h"

class Aabb
{
	public:
		Aabb();
		~Aabb();
		
		void SetMinMax(const vector3& min, const Vector3& max);
		void SetPosSize(const Vector3& position, const Vector3& size);
		
		const Vector3& GetMin() const;
		const Vector3& GetMax() const;
		
		bool Intesect(const Aabb& aabb);	
	private:
		Vector3 m_min;
		Vector3 m_max;
};
#endif
