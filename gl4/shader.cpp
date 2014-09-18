#include "shader.h"

Shader::Shader()
{

}

Shader::~Shader()
{

}

void Shader::SetSource(const std::string& shaderSource, GLenum shaderType)
{

}

void Shader::LoadShader(const std::String& filename, GLenum shaderType)
{

}

void Shader::Link()
{

}

void Shader::Bind()
{

}

void Shader::Unbind()
{

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
