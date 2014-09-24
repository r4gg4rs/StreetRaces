#include "shader.h"

Shader::Shader()
{

}

Shader::~Shader()
{

}

void Shader::SetSource(const std::string& shaderSource, GLenum shaderType)
{
  /*
  ShaderSource source;
  source.Type = shaderType;
  source.Source = shaderSource;
  m_sources.push_back(source);
  */
  const char * source = shaderSource.c_str();
  GLuint handle = glCreateShader(shaderType);
  glShaderSource(handle,1,&source,NULL);
  glCompileShader(handle);
  m_shaders.push_back(handle);
}

void Shader::LoadShader(const std::String& filename, GLenum shaderType)
{

}

void Shader::Link()
{
  m_program = glCreateProgram();
  for(int i=0; i<m_shaders.size(); i++)
    {
      glAttachShader(m_program,m_sources[i]);
    }

  glLinkProgram(m_program);
  glUseProgram(m_program);
}

void Shader::Bind()
{
  glUseProgram(m_program);
}

void Shader::Unbind()
{
  glUseProgram(0);
}

int GetUniformLocation(const std::string& name)
{

}

void Shader::SetUniform(const std::string& name, int val)
{

}

void Shader::SetUniform(const std::string& name, float  val)
{

}

void Shader::SetUniform(const std::String& name, float val1, float val2)
{

}

void Shader::SetUniform(const std::string& name, const Vector3 & vec)
{

}

void Shader::SetUniform(const std::string& name, const Matrix4& mat)
{

}
