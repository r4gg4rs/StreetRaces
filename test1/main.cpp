
#include "../framework/IWindow.h"
#include "../framework/RenderingSystem.h"
#include "../framework/imesh.h"

#include "../GL/GL_RenderingSystem.h"
#include "../graphics/Mesh.h"
#include "../core/MeshObject.h"
#include "../GLUT/GLUT.inc"
#include "../GLUT/GLUT_Window.h"

#include <string>

SR::IWindow* p_window;

int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  p_window = new SR::WindowGLUT();
  std::string testi = "testi";
  p_window->Create(testi, 200,200);
  glutMainLoop();
  
  
  
  SR::MeshObject* object = new SR::MeshObject();
  
  SR::Mesh* mesh = new SR::Mesh();
  
  object->SetMesh(mesh);
  /*
  SR::RenderingSystem* renderingSystem = new SR::GL_RenderingSystem();
  renderingSystem->Add(object);
*/
	return 0;	
}
