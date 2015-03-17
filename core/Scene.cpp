#include "Scene.h"
#include <iostream>

using namespace SR;

Scene::Scene()
{
  
}

Scene::~Scene()
{
  
}
/*

void Scene::Add(IEntity *entity)
{
  
}
*/
void Scene::Add(MeshObject* obj)
{
  m_meshObjects.push_back( obj); 
}

void Scene::Render(IRenderer* renderer)
{
    //std::cout << "Scene render"<< m_meshObjects.size() <<std::endl;
    for(unsigned int i=0; i < m_meshObjects.size(); i++)
    {
      if(m_meshObjects[i]->NeedsToRender())
      {
         //std::cout <<"needs to render "<< i << std::endl;
        renderer->Render(m_meshObjects[i]);
      }
    }
}

void Scene::InitMeshes(IRenderer* renderer)
{
  for(unsigned int i=0; i< m_meshObjects.size(); i++)
  {
      renderer->InitMesh(m_meshObjects[i]->GetMesh());
  }
}
