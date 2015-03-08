
#include "GL_ElementBuffer.h"

using namespace SR;

GL_ElementBuffer::GL_ElementBuffer()
{
  glGenBuffers(1,&m_bufferID);
}

GL_ElementBuffer::~GL_ElementBuffer()
{
  
}

void GL_ElementBuffer::SetData(std::vector<unsigned int>& data)
{
  glBindBuffer(GL_ELEMENT_BUFFER, m_bufferID);
  glBufferData(GL_ELEMENT_BUFFER, sizeof(unsigned int) * data.size(),&data, GL_STATIC_DRAW);
}

void GL_ElementBuffer::Bind()
{
  glBindBuffer(GL_ELEMENT_BUFFER, m_bufferID);
}
