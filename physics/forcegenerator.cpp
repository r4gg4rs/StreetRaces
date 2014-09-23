#include "forcegenerator.h"

void ForceRegistry::Add(Body* body, ForceGenerator* fg)
{
  BodyForce bf;
  bf.body = body;
  bf.forceGenerator = fg;
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
  for(int i=0; i< registrations.size(); i++)
    {
      registrations[i].forceGenerator.UpdateForce(
                                                  registrations[i].body,
                                                  dt );
                                               
    }
}

