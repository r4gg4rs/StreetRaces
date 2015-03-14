#include "Shader.h"
#include <iostream>
using namespace SR;

Shader::Shader()
{

}

Shader::~Shader()
{
	for(unsigned int i=0; i < m_shaders.size(); i++) 
	{
		glDeleteShader( m_shaders[i]);
	}
	glDeleteProgram( m_programHandle);
}

void Shader::SetSource(std::string& source, GLenum shaderType)
{
	SetSource(source.c_str(), shaderType);
}

void Shader::SetSource(const char* source, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	const char** sSource = &source;
	glShaderSource(shader,1,sSource,NULL );
	glCompileShader(shader);

	GLint result;
	glGetShaderiv(shader,GL_COMPILE_STATUS,&result);

	if(result == GL_FALSE) 
	{
		fprintf(stderr, "Shader error\n" );
		
		GLint logLength;
		glGetShaderiv(shader,GL_INFO_LOG_LENGTH, &logLength);
		
		if( logLength > 0 )
		{
		  char * log = (char*)malloc(logLength);
		  GLsizei written;
		  glGetShaderInfoLog(shader,logLength,&written, log);
		  
		  
		  fprintf(stderr,"Shader log:\n%s",log);
		  free(log);
		}
	} else
	{
	  std::cout <<"Shader compiled OK "<<std::endl;
	}

	m_shaders.push_back(shader);
}

void Shader::Link()
{
  m_programHandle = glCreateProgram();
	for(unsigned int i = 0; i<m_shaders.size(); i++ )
	{
		glAttachShader(m_programHandle, m_shaders[i]);
	}

	glLinkProgram( m_programHandle);

	GLint status;
	glGetProgramiv(m_programHandle,GL_COMPILE_STATUS,&status);
	
	if(status == GL_FALSE)
	{
	  std::cout <<"SHADER : Error"<<std::endl;
		fprintf(stderr, "Shader : linkking error\n" );
	} else
	{
	  std::cout <<"Shader : linked"<<std::endl;
	}
	
	
	/*
	GLint nUniforms, maxLen;
  glGetProgramiv( m_programHandle, GL_ACTIVE_UNIFORM_MAX_LENGTH,&maxLen);
  glGetProgramiv( m_programHandle, GL_ACTIVE_UNIFORMS,&nUniforms);
	
	
	GLchar * name = (GLchar *) malloc( maxLen );
	GLint size, location;
	
  GLsizei written;
  GLenum type;
  printf(" Location | Name\n");
  printf("------------------------------------------------\n");
  for( int i = 0; i < nUniforms; ++i ) {
    glGetActiveUniform( m_programHandle, i, maxLen, &written,
    &size, &type, name );
    location = glGetUniformLocation(m_programHandle, name);
    printf(" %-8d | %s\n", location, name);
  }
  free(name);
  */
}

void Shader::Bind()
{
	glUseProgram( m_programHandle);
}

void Shader::Unbind()
{
	glUseProgram(-1);
}


void Shader::BindAttribLocation(int location, std::string& name)
{
	glBindAttribLocation( m_programHandle,location,name.c_str());
}


int Shader::GetUniformLocation(const char* name)
{
  int loc = glGetUniformLocation(m_programHandle,name);
	return loc;
}


void Shader::SetUniform(std::string& name, int value)
{

}


void Shader::SetUniform(std::string& mame, float value)
{

}


void Shader::SetUniform(std::string& name, float value1, float value2)
{

}

void Shader::SetUniform(std::string& name, float value1, float value2,float value3)
{

}

void Shader::SetUniform(const char* name, const Vector3& vec)
{
  int loc = glGetUniformLocation(m_programHandle,name);
  std::cout << "Shader Uniform " << name <<" " << loc << std::endl;
  glUniform3fv(loc,1, vec.Ptr());
}

void Shader::SetUniform(const char* name, const Matrix4& mat)
{
   int loc = glGetUniformLocation(m_programHandle,name);
  std::cout << " Shader uniform " << name << " " << GetUniformLocation(name) << std::endl;
//  std::cout << "Loc " << loc << std::endl;
  
  glUniformMatrix4fv(GetUniformLocation(name),1,false, mat.Ptr());
}
