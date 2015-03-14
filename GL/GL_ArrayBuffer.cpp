#include "GL_ArrayBuffer.h"
#include <iostream>


using namespace SR;

GL_ArrayBuffer::GL_ArrayBuffer()
{
  glGenBuffers(1, &m_bufferID);
}

GL_ArrayBuffer::~GL_ArrayBuffer()
{
  
}

void GL_ArrayBuffer::SetData(std::vector<Vector3>& data)
{
  //glGenBuffers(1, &m_bufferID);
  std::cout <<"GL_ArrayBuffer : Set data" <<std::endl;
  std::cout <<" Buffer ID :  " << m_bufferID << " \n data size " << data.size() << std::endl;
  glBindBuffer(GL_ARRAY_BUFFER,m_bufferID);
  glBufferData(GL_ARRAY_BUFFER,sizeof(Vector3)*data.size(), &data,GL_STATIC_DRAW);
  
}

void GL_ArrayBuffer::Bind()
{
  glBindBuffer(GL_ARRAY_BUFFER,m_bufferID);
}