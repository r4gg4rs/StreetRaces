

#include "GLUT_Window.h"

WindowGLUT::WindowGLUT()
{
  
}

WindowGLUT::~WindowGLUT()
{
  
}

void WindowGLUT::Create(std::string& name, int width, int height)
{
  m_width = width;
  m_height = height;
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(m_width, m_height);
  glutCreateWindow(name.c_str());
}


void WindowGLUT::Resize(int width, int height)
{
  
}