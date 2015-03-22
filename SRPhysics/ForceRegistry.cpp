#include "ForceRegistry.h"

using namespace SR;

void ForceRegistry::Add(ForceGeneratorPtr forceGen, BodyPtr body)
{
  FG_Body fgBody;
  fgBody.generator = forceGen;
  fgBody.body = body;
  
  m_registry.push_back(fgBody);
}



void ForceRegistry::Remove(ForceGeneratorPtr forceGen, BodyPtr body)
{
  
}


void ForceRegistry::Update(Real dt)
{
  for(Index i=0; i< m_registry.size(); i++)
  {
    m_registry[i].generator->Update(m_registry[i].body, dt);
  }
}
