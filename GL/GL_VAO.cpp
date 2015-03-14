#include "GL_VAO.h"

using namespace SR;

Vao::Vao()
{
  //glGenVertexArrays(1, &m_vaoID);
  //glEnableVertexAttribArray(0);
  //glEnableVertexAttribArray(m_vaoID);
}

Vao::~Vao()
{ 
  
}

void Vao::AddBuffer(IBuffer* buffer)
{
 m_buffers.push_back( buffer);


}

void Vao::Init()
{
  Bind();
  for(unsigned int i=0; i< m_buffers.size(); i++)
  {
    m_buffers[i]->Bind();  
  }
}

void Vao::SetData(std::vector<Vector3>& vertices, std::vector<unsigned int>& indices)
{
  GLuint vertBuffer;
  glGenBuffers(1,&vertBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vector3) * vertices.size(), &vertices[0],GL_STATIC_DRAW);
  
  glGenVertexArrays(1, &m_vaoID);
  glBindVertexArray(m_vaoID);
  glEnableVertexAttribArray(0);
  
  glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(GLubyte*) NULL);
  
  GLuint indexBuf;
  glGenBuffers(1,&indexBuf);
  
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuf);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);
  
  
  
}

void Vao::Bind()
{
  glBindVertexArray(m_vaoID);
}