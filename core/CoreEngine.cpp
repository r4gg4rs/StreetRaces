
#include "CoreEngine.h"
#include <iostream>
#include "../GLUT/GLUT.inc"

using namespace SR;

CoreEngine::CoreEngine()
{
  
}


CoreEngine::~CoreEngine()
{
  
}

/*
void CoreEngine::SetScene(IScene* scene)
{
  p_scene = scene; 
}
*/

void CoreEngine::SetScene(IScenePtr scene)
{
  p_scene = scene;
}


IScenePtr CoreEngine::GetScene()
{
  return p_scene;
}


void CoreEngine::SetRenderer(IRendererPtr renderer)
{
  p_renderer = renderer;
}

void CoreEngine::Render()
{

  if(p_renderer != NULL && p_scene != NULL) 
  {
   // std::cout << "Core engine render" << std::endl;
    p_renderer->Clear(); 
    p_scene->Render(p_renderer);
    glutSwapBuffers(); // TODO only glut
  }
}


IRenderer*  CoreEngine::GetRenderer()
{
  if(p_renderer != NULL) return p_renderer.get();
  else {
    std::cout <<"CoreEngine : Warning GetRenderer : No renderer found" << std::endl;
  }
  return NULL;
  
}


void CoreEngine::Update()
{
	Real dt = 0.0;
	
	for(Index i=0; i< p_engines.size(); i++ ) 
	{
		p_engines[i]->Update(dt);
	}  
}

void CoreEngine::Initialize()
{
	for(Index i=0; i < p_engines.size(); i++ ) 
	{
		p_engines[i]->Initialize();
	}
}

void CoreEngine::Start()
{

  if(p_renderer != NULL) 
  {
    //p_scene->InitMeshes(p_renderer);
  }
  
  for(Index i =0; i < p_engines.size(); i++ )
  {
  	p_engines[i]->Start();
  }
}

void CoreEngine::AddEngine( IEnginePtr engine ) 
{
	p_engines.push_back(engine);
}

