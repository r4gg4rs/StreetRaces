#ifndef "GL_VAO.h"

using namespace SR;

Vao::Vao()
{
  glGenVertexArrays(1, m_vaoID); 
}

Vao::~Vao()
{ 
  
}

void Vao::AddBuffer(IBuffer* buffer)
{
  //m_buffers.push_back( buffer);

  Bind();
  buffer->Bind();
}

void Vao::Bind()
{
  glBindVertexArray(m_vaoID);
}