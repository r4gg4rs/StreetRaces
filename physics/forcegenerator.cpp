#include "forcegenerator.h"
#include <iostream>

Gravity::Gravity(const Vector3& gravity) : m_gravity(gravity)
{
	std::cout << "ForceGenerator luotu " << std::endl;
}

Gravity::~Gravity()
{

}

void Gravity::UpdateForce(Body* body, float dt)
{
	body->AddForce(m_gravity * body->GetMass() );
}

void ForceRegistry::Add(Body* body, ForceGenerator* fg)
{
  BodyForcePair bf;
  bf.body = body;
  bf.forceGenerator = fg;
  registrations.push_back(bf);
}

void ForceRegistry::Remove(Body* body,ForceGenerator* fg)
{
  // TODO 
}

void ForceRegistry::Clear()
{

}

void ForceRegistry::UpdateForces(float dt)
{
  for(unsigned int i=0; i< registrations.size(); i++)
    {
      registrations[i].forceGenerator->UpdateForce(
                                                  registrations[i].body,
                                                  dt );
                                               
    }
}

