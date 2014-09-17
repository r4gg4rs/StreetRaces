#ifndef STREETRACER_SDL_APP_H
#define STREETRACER_SDL_APP_H

//#include "../app.h"
#include "sdl.inc"
#include <string>
class SdlApp
{
 public:
  static SdlApp* GetSingletonPtr();
  static SdlApp& GetSingleton();
  static void Delete();
  SdlApp();
  ~SdlApp();

	void Start();
  void Shutdown();
	private:
		int screen_pos_x = 100;
		int screen_pos_y = 100;
		int screen_width = 800;
		int screen_height = 400;
		std::string title;
		SDL_Window* p_window;
		SDL_GLContext m_context;
		
		bool m_runing;
};
#endif
