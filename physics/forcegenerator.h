#ifndef STREETRACER_PHYSICS_FORCEGENERATOR_H
#define STREETRACER_PHYSICS_FORCEGENERATOR_H

#include "../math/sr_math.h"
#include "body.h"

#include <vector>
/*
	Force generator interface
*/
class ForceGenerator
{
 public:
  virtual void UpdateForce(Body* body,float dt) = 0;
};

class Gravity : public ForceGenerator
{
	public:
		Gravity(const Vector3& gravity);
		~Gravity();
		virtual void UpdateForce(Body* body,float dt);
		
	private:
		Vector3 	m_gravity;
};

/*
	Force registry 
	
	holds body and forcegenerators
*/
class ForceRegistry 
{
 public:
  void Add(Body* body, ForceGenerator* fg);
  void Remove(Body* body, ForceGenerator* fg);
  void Clear();
  void UpdateForces(float dt);
 private:
 
  struct BodyForcePair
  {
    Body* body;
    ForceGenerator* forceGenerator;
  };
  typedef std::vector<BodyForcePair> Registery;
  Registery registrations;

};
#endif
