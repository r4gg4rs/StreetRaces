#ifndef STREETRACER_PHYSICSMANAGER_H
#define STREETRACER_PHYSICSMANAGER_H

#include "body.h"
#include "forcegenerator.h"
#include <vector>
#include <string>
#include <map>

/*
struct BodyForce
{
	ForceGenerator* forceGenerator;
	Body*						body;
};
*/

class PhysicsManager
{
 public:
  static PhysicsManager* GetSingletonPtr();
  static PhysicsManager& GetSingleton();
  static void Delete();
  
  void Initialize();
  void ShutDown();

	void Update(float dt);

  Body* GetNewBody(std::vector<std::string> forceGenerators);
  void AddBody(Body* body);
 private:
  PhysicsManager();
  ~PhysicsManager();

 private:
 //	std::map<std::string,(void)(*Create)()> m_generatorCreater;
  std::vector<Body*> m_bodys;
	std::map<std::string,ForceGenerator*> m_generators;
  ForceRegistry 	 	 m_registry;  
  
};
#endif
