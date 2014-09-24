#include "cameramanager.h"

CameraManager::CameraManager()
{

}

CameraManager::~CameraManager()
{

}


CameraManager* CameraManager::GetSingletonPtr()
{
  static CameraManager* instance;
  if(instance == NULL)
    {
      instance = new CameraManager();
      instance->Start();
    }
  return instance;
}

CameraManager& CameraManager::GetSingleton()
{
  return *GetSingletonPtr();
}

void CameraManager::Delete()
{
  CameraManager* manager = GetSingletonPtr();
  manager->Shutdown();
  delete manager;
}

void CameraManager::Start()
{

}

void CameraManager::Shutdown()
{

}
