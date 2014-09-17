#ifndef STREETRACER_SCENE_H
#define STREETRACER_SCENE_H

#include "gameobject.h"

class Scene
{
 public:
  Scene();
  ~Scene();
  void Initialize();
  void Shutdown();
  void AddObject(GameObject* object);
 private:
  std::list<GameObject*>
};
#endif
