#include "Scene2.h"
#include <iostream>
using namespace SR;

Scene::Scene()
{
  
}

Scene::~Scene()
{
  
}

void Scene::InitMeshes(IRendererPtr renderer)
{
  
}

void Scene::Render(IRendererPtr renderer)
{
  //std::cout << "render"<<std::endl;
  NodeObject::Render(renderer);
}