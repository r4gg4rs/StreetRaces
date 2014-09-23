#ifndef STREETRACER_EVENTMANAGER_H
#define STREETRACER_EVENTMANAGER_H

#include <iostream>

class EventManager 
{
 public:
  static EventManager* GetSingletonPtr();
  static EventManager& GetSingleton();
  static void Delete();

  void Initialize();
  void ShutDown();

 private:
  EventManager();
  ~EventManager();
};
#endif