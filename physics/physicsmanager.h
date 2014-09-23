#ifndef STREETRACER_PHYSICSMANAGER_H
#define STREETRACER_PHYSICSMANAGER_H

#include "body.h"

#include <vector>

class PhysicsManager
{
 public:
  static PhysicsManager* GetSingletonPtr();
  static PhysicsManager& GetSingleton();
  static void Delete();
  
  void Initialize();
  void ShutDown();

  Body* GetNewBody();
  void AddBody(Body* body);
 private:
  PhysicsManager();
  ~PhysicsManager();

 private:
  std::vector<Body*> m_bodys;
};
#endif
