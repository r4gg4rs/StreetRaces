
#include "GL_RenderingSystem.h"

#include "GL_VAO.h"
#include "../framework/IBuffer.h"
#include "GL_ElementBuffer.h"
#include "GL_ArrayBuffer.h"

using namespace SR;

GL_RenderingSystem::GL_RenderingSystem()
{
  p_renderer = new GL_Renderer();
}

GL_RenderingSystem::~GL_RenderingSystem()
{
  
}
/*
void GL_RendingSystem::Add(IMesh* mesh )
{
  Vao* vao = new Vao();
  
  GL_ArrayBuffer* buffer = new GL_ArrayBuffer();
  buffer->SetData(mesh->GetVertices());
  
  vao->AddBuffer( buffer );
  
  std::vector<unsigned int> indices = mesh->GetIndices();
  if(indices.size() > 0) 
  {
    GL_ElementBuffer* elemBuffer = new GL_ElementBuffer();
    elemBuffer->SetData(indices);
    vao->AddBuffer(elemBuffer);
  }
  
  VaoObject* object = new VaoObject();
  
}
*/

void GL_RenderingSystem::Add(IMeshObject* obj)
{
  IMesh* mesh = obj->GetMesh();
  
   Vao* vao = new Vao();
  
  GL_ArrayBuffer* buffer = new GL_ArrayBuffer();
  buffer->SetData(mesh->GetVertices());
  
  vao->AddBuffer( buffer );
  
  std::vector<unsigned int> indices = mesh->GetIndices();
  if(indices.size() > 0) 
  {
    GL_ElementBuffer* elemBuffer = new GL_ElementBuffer();
    elemBuffer->SetData(indices);
    vao->AddBuffer(elemBuffer);
  }
  
  VaoObject* object = new VaoObject(obj,vao);
  m_renderables.push_back( object );
}

void GL_RenderingSystem::Render()
{
  for(unsigned int i=0; i < m_renderables.size(); i++)
  {
    m_renderables[i].Render();
  }
}

void GL_RenderingSystem::Render(std::vector<unsigned int>& renderList)
{
  
}