#include "physicsmanager.h"

PhysicsManager::PhysicsManager()
{

}

PhysicsManager::~PhysicsManager()
{

}

PhysicsManager* PhysicsManager::GetSingletonPtr()
{
  static PhysicsManager* instance;
  if( instance == NULL)
    {
      instance = new PhysicsManager();
      instance->Initialize();
    }
  return instance;
}

PhysicsManager& PhysicsManager::GetSingleton()
{
  return *GetSingletonPtr();
}


void PhysicsManager::Delete()
{
  PhysicsManager *manager = GetSingletonPtr();
  manager->ShutDown();
  delete manager;
}

void PhysicsManager::Initialize()
{
	Vector3 gravity = Vector3(0.0f,9.81f,0.0f);
	std::string name = "Gravity";
	ForceGenerator* fg = new Gravity(gravity);
	m_generators[name] = fg;
}

void PhysicsManager::ShutDown()
{

}


void PhysicsManager::Update(float dt)
{
	m_registry.UpdateForces(dt);
}

// TODO make creator so that it can be flexibly update later
// save functio pointer to static ForceGenerator creator
// check if m_generator allready have force generator
// if not make new and save it to the list
Body* PhysicsManager::GetNewBody(std::vector<std::string> fg)
{
  Body* body = new Body();
  // Temp
  
 
  for( unsigned int i = 0; i< fg.size(); i++)
  {
  	
		std::map<std::string, ForceGenerator*>::iterator it = m_generators.find( fg[i] );
	
		if( it != m_generators.end() )
		{
			m_registry.Add(body, it->second );	
		}
	}  	  
  
  /*
  for(unsigned int i=0; i< fg.size(); i++)
  {
  	std::map<std::string,ForceGenerator*> iterator it = m_generators.find(fg[i]);
  	
  	if(it == m_generators.end())
  	{
  		std::map<std::string,(void)(*Create)()> iterator cit = m_generatorCreator.find( fg[i] );
  		
  		if(cit != m_generatorCreator.end() )
  		{
  			(void)(*Create)() =cit.second();
  			ForceGenerator* gen = Create();
  			m_generators.push_back(gen);	
  			m_registry.Add(body, gen);
  		}
  	}else
  	{
  		m_registry.Add(body, it.second );
  	} 
  }
	m_generatorMap
  m_bodys.push_back(body);
 	*/
  return body;
}


void PhysicsManager::AddBody(Body* body)
{
  m_bodys.push_back(body);
}
