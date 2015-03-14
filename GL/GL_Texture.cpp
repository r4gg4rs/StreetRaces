#include "GL_Texture.h"

GL_Texture::GL_Texture() : m_target(GL_TEXTURE_2D), m_wrap_s(GL_REPEAT), m_weap_t(GL_REPEAT), m_filter_min(GL_LINEAR), m_filter_mag(GL_LINEAR)
{
  glGenTextures(1,m_handle);
}

GL_Texture::~GL_Texture()
{
  
}


void GL_Texture::SetImageData(Image image)
{
  m_image = image;
  
  glTexParameteri(m_target, GL_TEXTURE_WRAP_S, m_wrap);
  glTexParameteri(m_target, GL_TEXTURE_WRAP_T, m_wrap);
 
 	glTexParameteri(m_target, GL_TEXTURE_MIN_FILTER, m_filter_min);
 	glTexParemeteri(m_target, GL_TEXTURE_MAG_FILTER, m_filter_mag);
 	
 	glTexImage(m_target,0,GL_RGBA, p_imager->columns(), p_image->rows(),0,GL_RBGA,GL_UNSIGNED_BYTE, image.data)
}




void GL_Texture::Bind()
{
  
}
