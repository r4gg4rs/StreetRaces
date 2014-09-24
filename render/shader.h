#ifndef STREETRACER_SHADER_H
#define STREETRACER_SHADER_H

#include <vector>
#include <string>
#include "../math/math_inc.h"
/*
namespace Shader
{
  enum type {GL_VERTEX_SHADER,GL_FRAGMENT_SHADER, GL_GEOMETRY_SHADER,GL_TESS_EVALUATION_SHADER,GL_TESS_CONTROLL_SHADER } 
};
*/
struct ShaderSource
{
  GLenum Type;
  std::string Source; 
};
 
class Shader
{
 public:
  Shader();
  ~Shader();
  void SetSource(const std::string& shaderSource, GLenum shadertype);
  void LoadSource(const std::string& filename,GLenum shadertype);
  void Link();
  void Bind();
  void Umbind();
  int GetUniformLocation(const std::string& name);
  void SetUniform(const std::string& name, int val);
  void SetUniform(const std::string& name, float val);
  void SetUniform(const std::string& name, float val1, float val2);
  void SetUniform(const std::string& name, const Vector3 &cvec);
  void SetUniform(const std::string& name, const Matrix4 &mat);
 private:
  GLuint m_program;
  std::vector<ShaderSource> m_sources;
  std::vector<GLuint> m_shaders;
};
#endif
