#ifndef STREETRACER_SDL_EVENTMANAGER_H
#define STREETRACER_SDL_EVENTMANAGER_H

#include <SDL2/SDL.h>
#include <iostream>
#include "../controllable.h"
#include "../carcontroller.h"
#include "../carcontkeyboard.h"
#include "../ecar.h"
//#include "../eventmanager.h"
#include <vector>
#include <map>


class ECar;
/*
typedef void(Controllable::*ControlFunc)();
struct key_pair
{
  SDL_Keycode key;
  ControlFunc function;
};
*/
class SdlEventManager// :  public EventManager
{
public:
  static SdlEventManager* GetSingletonPtr();
  static SdlEventManager& GetSingleton();
  static void Delete();

  void Initialize();
  void ShutDown();
  void Update();

//void RegisterEvent(SDL_Keycode key, ControlFunc* function);

  //CarController* GetCarController();
  void SetCar(ECar * car);
 private:
  SdlEventManager();
  ~SdlEventManager();
  //CarController* p_carController;
  ECar * p_car;
//std::map<SDL_Keycode,ControlFunc* > m_events;
};
#endif
