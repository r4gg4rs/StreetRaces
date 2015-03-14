#ifndef SR_GL_TEXTURE_H
#define SR_GL_TEXTURE_H

#include "../GLUT/GLUT.inc"

namespace SR
{ 
 struct Image
 {
 		unsigned char* 	data;
 		int							width;
 		int 						height;
 }
  
  class GL_Texture
  {
    private:
      GLuint      m_handle;
      GLenum      m_target;   			// default GL_TEXTURE_2D
      GLenum      m_wrap_s;     		// default GL_REPEAT
      GLenum      m_wrap_t;     		// default GL_REPEAT
      GLenum      m_filter_min; 		// default GL_LINEAR
      GLenum      m_filter_mag;			// default GL_LINEAR
      
      Image    		m_image;

    public: 
      GL_Texture();
      ~GL_Texture();
      
      void    SetImageData(Image  image);    
  
      void Bind();
  };
}
#endif
