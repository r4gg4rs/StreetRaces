#include "PhysicsEngine.h"

using namespace SR;

void PhysicsEngine::Initialize()
{

}

void PhysicsEngine::Start() 
{

}

void PhysicsEngine::Add(BodyPtr body, std::vector<std::string> forces)
{
	for(unsigned int i=0; i< forces.size(); i++ ) 
	{
		std::string name = forces[i];
		ForceGeneratorPtr generator = m_generatorMap[ name ]();
		m_forceRegistry.Add( generator, body);
	}
}


void PhysicsEngine::Add(BodyComponentPtr component, std::vector<std::string> forces)
{
  Add(component->body, forces);
  m_componentlist.push_back( component);
}


void PhysicsEngine::Add(BodyComponentPtr component)
{
  m_componentlist.push_back( component);
}


void PhysicsEngine::Update(Real dt) 
{
	// aply forces
	// update position and velocity
	// detect collision
	// solve constraints
	
	m_forceRegistry.Update( dt);
	/*
	// Test collision
	for(unsigned int i=0; i< m_componentlist.size()-1; i++) 
	{
	  for(unsigned int j=i+1; j <m_componentlist.size();j++)
	  {
	    CollisionData data = m_componentlist[i]->colider->Intersect(m_componentlist[j]->colider);
	    if(data.intersect) // coliding
	    {
	      
	    }
	  }
	}
	*/
}


void PhysicsEngine::RegisterGenerator(std::string name, GetGenerator generator)
{
	m_generatorMap[name] = generator;
}

