#include "physicsmanager.h"

PhysicsManager::PhysicsManager()
{

}

PhysicsManager::~PhysicsManger()
{

}

PhysicsManager* PhysicsManager::GetSingletonPtr()
{
  static PhysicsManger* instance;
  if( instance == NULL)
    {
      instance = new PhysicsManager();
    }
  return instance;
}

PhysicsManager& PhysicsManager::GetSingleton()
{
  return *GetSingletonPtr();
}
void PhysicsManager::Delete()
{
  PhysicsManger *manager = GetSingletonPtr();
  manager->ShutDown();
  delete manager;
}

void PhysicsManager::Initialize()
{

}

void PhysicsManager::ShutDown()
{

}


Body* PhysicsManager::GetNewBody(std::vector<string> forceGenerators);
{
  Body* body = new Body();

  m_bodys.push_back(body);
}


void PhysicsManager::AddBody(Body* body)
{
  m_bodys.push_back(body);
}
