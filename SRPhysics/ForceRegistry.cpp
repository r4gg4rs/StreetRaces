#include "ForceRegistration.h"

void ForceRegistry::Add(ForceGeneratorPtr forceGen, BodyPtr body)
{
  FG_Body fgBody;
  fgBody.generator = forceGen;
  fgBody.body = body;
  
  registry.push_back(fgBody);
}



void ForceRegistry::Remove(ForceGeneratorPtr forceGen, BodyPtr body)
{
  
}


void ForceRegisty::Update(Real dt)
{
  for(Index i=0; i< registry.size(); i++)
  {
    registry[i].generator->Update(registry[i].body, dt);
  }
}