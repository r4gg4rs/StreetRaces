#ifndef SR_SCENEMANAGER_H
#define SR_SCENEMANAGER_H

#include "scene.h"

class SceneManager
{
	public:
		static SceneManager* GetSingletonPtr();
		static SceneManager& GetSingleton();
		static void Delete();
	public:
		void StartUp();
		void ShutDown();
		Scene* GetScene();
		
		
	private:
		SceneManager();
		~SceneManager();
		
	private:
		Scene* p_scene;
};
#endif
