#include "sdl_eventmanager.h"
#include <iostream>
#include "sdl_app.h"

SdlEventManager::SdlEventManager()
{

}

SdlEventManager::~SdlEventManager()
{

}

SdlEventManager* SdlEventManager::GetSingletonPtr()
{
  static SdlEventManager* instance;
  if(instance == NULL)
    {
      instance = new SdlEventManager();
    }

  return instance;
}

SdlEventManager& SdlEventManager::GetSingleton()
{
  return *GetSingletonPtr();
}

void SdlEventManager::Delete()
{
  SdlEventManager* manager =GetSingletonPtr();
  manager->ShutDown();
  delete manager;
}

void SdlEventManager::Initialize()
{

}

void SdlEventManager::ShutDown()
{

}

void SdlEventManager::Update()
{
  SDL_Event event;
  if(SDL_PollEvent(&event))
    {
      //if(event.type == SDL_QUIT)break;// m_runing =  false;
      
      if(event.type == SDL_QUIT)SdlApp::GetSingleton().Stop();
      if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE) SdlApp::GetSingleton().Stop();
      if(event.type ==SDL_KEYDOWN)
        {
          switch(event.key.keysym.sym)
            {
            case SDLK_UP :
              if(p_car != NULL) p_car->Accelerate();
              // p_carController->Accelerate();
              //std::cout <<" Up "<<std::endl;
              break;
            case SDLK_DOWN :
              if(p_car != NULL) p_car->Brake();
              //p_carController->Brake();
              break;
            case SDLK_LEFT :
              if(p_car != NULL) p_car->TurnLeft();
              //p_carController->Turn(-0.1f);
              break;
            case SDLK_RIGHT:
              if(p_car == NULL) std::cout <<" car puuttuu "<< std::endl;
               if(p_car != NULL) p_car->TurnRight();
              //p_carController->Turn(0.1f);
              break;
            }
        }
    }
		

}
/*
void SdlEventManager::RegisterEvent(SDL_Keycode key,ControlFunc* func)
{
  m_events[key] = func;
}

CarController* SdlEventManager::GetCarController()
{
  if(p_carController == NULL)
    {
      p_carController = new CarCKeyboard();
    }
  return p_carController;
}
*/
void SdlEventManager::SetCar(ECar* car)
{
  p_car = car;
}

/*
  register string createrfunc

  GetController("CarControlle",
  
  CarController


 */
