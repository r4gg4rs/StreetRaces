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

void PhysicsEngine::Update(Real dt) 
{
	// aply forces
	// update position and velocity
	// detect collision
	// solve constraints
	
	m_forceRegistry.Update( dt);
}


void PhysicsEngine::RegisterGenerator(std::string name, GetGenerator generator)
{
	m_generatorMap[name] = generator;
}

