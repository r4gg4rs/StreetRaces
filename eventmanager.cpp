#include "eventmanager.h"

EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

EventManager* EventManager::GetSingletonPtr()
{
  static EventManager* instance;
  if(instance == NULL)
    {
      instance = new EventManager();
    }

  return instance;
}

EventManager& EventManager::GetSingleton()
{
  return *GetSingletonPtr();
}

void EventManager::Delete()
{
  EventManager* manager =GetSingletonPtr();
  manager->ShutDown();
  delete manager;
}

void EventManager::Initialize()
{

}

void EventManager::ShutDown()
{

}
