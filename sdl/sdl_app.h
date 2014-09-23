#ifndef STREETRACER_SDL_APP_H
#define STREETRACER_SDL_APP_H

//#include "../app.h"
#include "sdl.inc"
#include <string>
#include "../scene.h"
#include "sdl_eventmanager.h"

class SdlApp
{
 public:

  /*
    TODO ohjelman käynnistys
    tällä hetkellä uusi ikkuna syntyy kun 
    pyydetää ositinta tai referenssiä
   */
  static SdlApp* GetSingletonPtr();
  static SdlApp& GetSingleton();
  static void Delete();
  SdlApp();
  ~SdlApp();

  void Start();
  void Stop();
  void Shutdown();
  void Render();
  void Update();
	private:
		int screen_pos_x = 100;
		int screen_pos_y = 100;
		int screen_width = 800;
		int screen_height = 400;
		std::string title;
		SDL_Window* p_window;
		SDL_GLContext m_context;
                Scene m_scene;
		bool m_runing;
		SdlEventManager* p_eventManager;

                Uint32 m_prevTime;
};
#endif
