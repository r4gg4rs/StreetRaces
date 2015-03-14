
#include "GL_Renderer.h"

#include "GL_ArrayBuffer.h"
#include "GL_ElementBuffer.h"
#include "GL_VAO.h"
#include <iostream>
#include "../loader/loader.h"
using namespace SR;

GL_Renderer::GL_Renderer()
{
  /*
  	std::string vertexShader = "#version 400\n\
layout (location = 0) in vec3 VertexPosition;\n\
uniform mat4 projectionMatrix;\n\
void main()\n\
{\n\
gl_Position = projectionMatrix * vec4(VertexPosition, 1.0);\n\
}";

std::string fragmentShader ="#version 400\
out vec4 FragColor;\
void main() {\
FragColor = vec4(1.0, 0.0, 0.0, 1.0);\
}";


*/
  Loader *loader = Singleton<Loader>::GetSingletonPtr();
  
  std::string vertFile ="../data/shaders/test.vert";
  std::string fragFile ="../data/shaders/test.frag";
  
  std::string vertSource = loader->LoadShader(vertFile);
  std::string fragSource = loader->LoadShader(fragFile);
  m_col = Vector3(1.0,0.0,0.0);
 // std::cout << "Test loader vert " << vertSource << std::endl;
//  std::cout << "Test loader frag" << fragSource << std::endl;
  
  p_shader = new Shader();
  p_shader->SetSource( vertSource, GL_VERTEX_SHADER);
  p_shader->SetSource( fragSource, GL_FRAGMENT_SHADER);

  p_shader->Link();
  std::string vertPos = "Position";
	p_shader->BindAttribLocation(0,vertPos);

  glViewport(0,0,800,600);
  p_view = new int[4];


  p_view[0] = 0;
  p_view[1] = 0;
  p_view[2] = 800;
  p_view[3] = 600;
    
}

GL_Renderer::~GL_Renderer()
{
  
}

void GL_Renderer::SetClearColor(Color& color)
{
  m_clearColor = color;
  glClearColor(m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
}

void  GL_Renderer::Clear()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //std::cout << "clear"<<std::endl;
  
}

/*
  Generate buffers in mesh
*/
void  GL_Renderer::InitMesh(IMesh* mesh)
{
 /*
  GL_ArrayBuffer* posBuffer = new GL_ArrayBuffer();
  posBuffer->SetData(mesh->GetVertices());
  Vao* vao = new Vao();
  vao->AddBuffer(posBuffer);
  vao->Bind();
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(GLubyte*) NULL);
  
  // TODO other buffers
  GL_ElementBuffer* elemBuffer = new GL_ElementBuffer();
 

  
  vao->AddBuffer(elemBuffer);
  //vao->Init();
  mesh->AddBuffer(vao);
*/
  Vao* vao = new Vao();
  vao->SetData(mesh->GetVertices(), mesh->GetIndices());
}


void  GL_Renderer::Render(IMesh* mesh)
{
  mesh->Render();
//  std::cout <<"Render size " << mesh->GetSize() << std::endl;
  glDrawArrays(GL_TRIANGLES,0,mesh->GetSize());
 
}

void GL_Renderer::Render(MeshObject* object)
{
	std::cout<<"render"<<std::endl;
	//object->SetPosition(Vector3(-0.4, 6.2,0.4));
	
	//object->Rotate(Vector3(0.5,0.0,0.5),0.45);
/*  
  Vector3 pos = object->GetPosition();
  Vector3 newpos = pos + Vector3(0.002,0.0,0.0);
  object->SetPosition(newpos);
  */
  object->Rotate(Vector3(0.0,1.0,0.0), 0.001);
  
  IMesh* mesh = object->GetMesh();
  Matrix4 model = object->GetModelMatrix();

  p_shader->Bind();
  
  p_shader->SetUniform("color",m_col);
  p_shader->SetUniform("projectionMatrix", p_camera->GetProjectionMatrix());
  p_shader->SetUniform("viewMatrix" , p_camera->GetViewMatrix());
  p_shader->SetUniform("modelMatrix", model);


//  p_shader->SetUniform(viewName, p_camera->GetViewMatrix());
  mesh->Render();
  Matrix4 view = p_camera->GetViewMatrix();
 // view.Print();
  //Matrix4 projection = p_camera->GetProjectionMatrix();
  view.Print();
  
//  Matrix4 pv = view *projection;
//  pv.Print();
//  Matrix4 vp = projection * view;
//  vp.Print();
 /*
  for(unsigned int i=0; i < 16; i++)
  {
    std::cout <<"Matrix i " << i << " = "<< view[i] << std::endl;
  }
  */
  //glDrawArrays(GL_TRIANGLES,0, mesh->GetSize());  // Render whitout indices
  glDrawElements(GL_TRIANGLES, mesh->GetSize(), GL_UNSIGNED_INT,0);
  
  
  // Render child objects
  for(MeshObjectList::iteratori t= m_MOchilds.begin(); it != m_MOchilds.end() it++)
  {
  	Render( it );
  }
  
}


void GL_Renderer::SetViewport(int xMin, int yMin, int xMax, int yMax)
{
  glViewport( xMin, yMin, xMax, yMax);
}

int* GL_Renderer::GetViewport()
{
  //int* view;
  //glGetIntegerv(GL_VIEWPORT,p_view);
  return p_view;
}
