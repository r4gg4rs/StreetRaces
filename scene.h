#ifndef STREETRACER_SCENE_H
#define STREETRACER_SCENE_H

#include "gameobject.h"
#include <list>
#include <vector>
#include "entity.h"

class Scene
{
 public:
  Scene();
  ~Scene();
  void Initialize();
  //  void Shutdown();
  void AddObject(GameObject* object);
  void Render();
  void Update();
 private:
  std::vector<GameObject*> m_objects; // Switch to list
};
#endif
