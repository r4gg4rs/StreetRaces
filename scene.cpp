#include "scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::Initialize()
{
  Entity* entity = new Entity();
  entity->Load();
  AddObject(entity);
}
/*
??
void Scene::Shutdown()
{

}
*/
void Scene::AddObject(GameObject* object)
{
  m_objects.push_back(object);
}

void Scene::Render()
{
  for(int i=0; i<m_objects.size(); i++)
    {
      Entity* ent = dynamic_cast<Entity*> (m_objects[i]);
      ent->Render();
    }
}

void Scene::Update()
{

}
