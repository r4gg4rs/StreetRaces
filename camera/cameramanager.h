#ifndef STREETRACER_CAMERAMANAGER_H
#define STREETRACER_CAMERAMANAGER_H

#include <stdio.h>

class CameraManager
{
 public:
  static CameraManager* GetSingletonPtr();
  static CameraManager& GetSingleton();
  static void Delete();
  void Start();
  void Shutdown();
 private:
  CameraManager();
  ~CameraManager();
};

#endif
