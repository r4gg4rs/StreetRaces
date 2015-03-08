#ifndef SR_GLUT_WINDOW_H
#define SR_GLUT_WINDOW_H

#include "../framework/IWindow.h"

namespace SR
{
  class WindowGLUT : public IWindow
  {
    public:
      WindowGLUT();
      ~WindowGLUT();
    
      void Create(std::string& name, int width, int height);
      void Resize(int width, int height);
  
  
  };
}
#endif