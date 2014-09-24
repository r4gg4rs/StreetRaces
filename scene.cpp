#include "scene.h"
#include "renderable.h"
#include <SDL2/SDL.h>
#include "controllable.h"
#include <iostream>

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
  entity->SetPosition(Vector3(-2.2f,0.0f,2.0f));
  AddObject(entity);

  ECar* entcar = new ECar();
  entcar->SetPosition(Vector3( 2.0f,0.0f, -3.0f));
  entcar->Load();
  //entcar->SetPosition(Vector3(0.0f,0.0f,0.0f));
  SdlEventManager::GetSingleton().SetCar(entcar);
  p_camera = new Camera_Base();
  Entity *e = entcar;
  AddObject(e);


  Car* car = new Car();
  car->Load();
  AddObject(car);

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
  Entity* ent = dynamic_cast<Entity*> (object);
  m_entitys.push_back(ent);
}

void Scene::Render()
{

  //std::cout << m_entitys.size() << std::endl;
	glMatrixMode(GL_PROJECTION);
	
	Matrix4 view = p_camera->GetViewMatrix();
  Matrix4 projection = p_camera->GetProjectionMatrix();
  
	glLoadIdentity();
  
	glMultMatrixf(&projection[0][0]);
  	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMultMatrixf(&view[0][0]); 
	
  RenderState state;
  for(unsigned int i=0; i<m_entitys.size(); i++)
    {
  		m_entitys[i]->Render(state);
    }
}

void Scene::Update(float dt)
{
	for(unsigned int i=0; i < m_entitys.size(); i++)
	{
		m_entitys[i]->Update(0.0f);
	}
}
