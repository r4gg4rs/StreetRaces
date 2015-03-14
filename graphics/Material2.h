/**
*	Testing
**/

#ifndef SR_MATERIAL__H
#define SR_MATERIAL__H

#include "../core/base.inc"
#include "../GL/Shader.h"
#include "../core/Color.h"

namespace SR
{
	namespace T
	{
		struct Uniform
		{
			std::string		name;
			std::string		type;
			Color					value;
		};
		
		struct shaderElement
		{
			std::string		name;
			std::string		type;
		};
		
		typedef std::vector<Uniform>	Uniforms;
		enum MaterialType {SR_FLAT, SR_LAMBERT, SR_PHONG};
	
	
		class Material
		{
			private:
				std::vector<Uniform>		m_uniforms;
				Shader*									p_shader;
				MaterialType						m_type;
					
			public:
				Material();
				~Material();
				
				void		AddUniform(const Uniform& uniform);
				void		Initialize();
				void		SetColor(const Color& color);
				Shader*	GetShader();
				
				void		Apply();
				
		};
	}
}
#endif
