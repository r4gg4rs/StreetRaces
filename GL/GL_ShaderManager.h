#ifndef SR_GL_SHADERMANAGER_H
#define SR_GL_SHADERMANAGER_H

#include "../utils/singleton.h"
#include "Shader.h"
//#include "../graphics/Material.h"
#include "../graphics/Material2.h"

#include "../core/base.inc"
#include <list>
#include "../core/CoreEngine.h"

namespace SR
{
	struct ShaderElement
	{
		std::string 	name;
		std::string		type;
	};
	
	typedef std::vector<ShaderElement> Attributelist;
	typedef std::vector<ShaderElement> Uniformlist;

  class GL_ShaderManager : public Singleton<GL_ShaderManager>
  {
    private:
      CoreEnginePtr   p_coreEngine;
    
    public:
      GL_ShaderManager();
      ~GL_ShaderManager();
      
      /*
      Shader MakeShader(const Material& material)
      {
        bool useLighting;
        
        std::string vertexSource;
        std::string fragmentSource;
        
        ScenePtr scene = p_coreEngine->GetScene();
        
        
        if(useLighting) {
          std::string lightingUniforms =" struct Material {\n\
                                          vec3 ambientColor\n\
                                          vec3 diffuseColor\n\
                                          vec3 specularColor\n\
                                          float shininess\n\
                                          }\n}
                                          uniform Material material\n
                                          struct Light";
          useLightin.append  
        }
      }
      */
      ShaderPtr MakeShader( Attributelist& attributelist, Uniformlist& uniformlist, MaterialType materialtype);
      
      private:
      	void MakeFlatShading(std::string& source );
      	void MakeLambertShading(std::string& source);
      	void MakePhongShading(std::string& source);
  };
  
  typedef std::shared_ptr<GL_ShaderManager> GL_ShaderManagerPtr;
}
#endif
