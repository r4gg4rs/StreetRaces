#include "scenemanger.h"

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

SceneManager* SceneManager::GetSingletonPtr()
{
	static SceneManager* instance;
	if( instance == NULL)
	{
		instance = new SceneManager();
		instance->StartUp();
	}
}

SceneManager& SceneManager::GetSingleton()
{
	return *GetSingletonPtr();
}

void SceneManager::Delete()
{
	SceneManager* manager = GetSingletonPtr();
	manager->ShutDown();
	delete manager;
}

void SceneManager::StartUp()
{

}

void SceneManager::ShutDown()
{

}

Scene* SceneManager::GetScene()
{
	if(p_scene == NULL)
	{
		p_scene = new Scene();
	}
	return p_scene;
}
