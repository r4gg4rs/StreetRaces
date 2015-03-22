/**
*	Testing
**/

#ifndef SR_MATERIAL__H
#define SR_MATERIAL__H

#include "../core/base.inc"
#include "../GL/Shader.h"
#include "../core/Color.h"
#include "../framework/IMesh.h"
namespace SR
{
		typedef std::shared_ptr<IMesh> IMeshPtr;
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
				ShaderPtr								p_shader;
				MaterialType						m_type;
					
			public:
				Material();
				~Material();
				
				void		    AddUniform(const Uniform& uniform);
				void		    Initialize();
				void        Initialize(IMeshPtr mesh);
				void		    SetColor(const Color& color);
				ShaderPtr   GetShader();
				
				void	    	Apply();
				
		};
		
	  typedef std::shared_ptr<Material> MaterialPtr;
}
#endif
