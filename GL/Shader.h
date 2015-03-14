#ifndef CHOPPER_RENDERING_SHADER_H
#define CHOPPER_RENDERING_SHADER_H

#include "../core/base.inc"
#include "../GLUT/GLUT.inc"
#include "../math/math.inc"

namespace SR
{

		class Shader
		{
		public:
			Shader();
			~Shader();
			void SetSource(std::string& source, GLenum shaderType);
			void SetSource(const char* source, GLenum shaderType);
			void Link();
			void Bind();
			void Unbind();

			void BindAttribLocation(int location, std::string& name);

			int GetUniformLocation(const char* name);
			void SetUniform(std::string& name, int value);
			void SetUniform(std::string& mame, float value);
			void SetUniform(std::string& name, float value1, float value2);
			void SetUniform(std::string& name, float value1, float value2,float value3);
			void SetUniform(const char* name, const Vector3& value);
			void SetUniform(const char*, const Matrix4& value);

		public:
			std::vector<GLint> 			m_shaders;
			GLuint						m_programHandle;
		};
}
#endif
