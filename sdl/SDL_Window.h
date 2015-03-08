#ifndef STREETRACER_SDL_WINDOW_H
#define STREETRACER_SDL_WINDOW_H

#include "sdl_inc.h"
#include "../framework/IWindow.h"

namespace SR
{
  class WindowSDL
  {
    public
      WindowSDL();
      ~WindowSDL();
      
      virtual void Create(std::string& name, int width, int height;
      virtual void Resize(int width, int height);
      
    private:
      SDL_Surface*    p_window;
      bool            m_isFullScreen;
  };
}
#endif