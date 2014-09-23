#ifndef STREETRACER_SCENE_H
#define STREETRACER_SCENE_H

#include "gameobject.h"
#include <list>
#include <vector>
#include "entity.h"
#include "ecar.h"
#include "./camera/icamera.h"
#include "./camera/camera_base.h"
#include "./sdl/sdl_eventmanager.h"

#include "./physics/test/car.h"

class Scene
{
 public:
  Scene();
  ~Scene();
  void Initialize();
  //  void Shutdown();
  void AddObject(GameObject* object);
  void Render();
  void Update(float dt);
 private:
  std::vector<GameObject*> m_objects; // Switch to list
  std::vector<Entity*> m_entitys;
 	ICamera* p_camera;
};
#endif
