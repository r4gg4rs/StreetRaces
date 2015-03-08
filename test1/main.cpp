#include "./sdl/sdl_app.h"

#include "../framework/IWindow.h"
IWindow* p_window;
int main(int argc, char** argv)
{
  glutInit(argc,argv);
  p_window = new SR::WindowGLUT();
  
  SR::MeshObject* object = new SR::MeshObject();
  
  SR::Mesh* mesh = new SR::Mesh();
  object->SetMesh(mesh);
  
  SR::RenderingSystem* renderingSystem = new SR::GL_RenderingSystem();
  renderingSystem->Add(object);
	return 0;	
}
