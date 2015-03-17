#include "GL_ShaderManager.h"

using namespace SR;


GL_ShaderManager::GL_ShaderManager()
{
    p_coreEngine = Singleton<CoreEngine>::GetSingletonSPtr();
}

GL_ShaderManager::~GL_ShaderManager()
{

}

ShaderPtr GL_ShaderManager::MakeShader( Attributelist& attributelist, Uniformlist& uniformlist, MaterialType materialtype)
{
	ShaderPtr shader(new Shader);
	std::string vertexSource = "#vertion 400 \n ";
	std::string fragmentSource = "#version 400 \n";
	
	
	// Attributes
//	for(Attributelist::iterator i= attributelist.begin(); i != attributelist.end(); i++) 
	for(unsigned int i = 0; i< attributelist.size(); i++)
	{
		vertexSource.append("in " + attributelist[i].type + " " + attributelist[i].name + ";\n");
	}
	
	// TODO out
	vertexSource.append(" out vec4 frag_color;");
	
	
	vertexSource.append("uniform mat4 projectionMatrix; \n");
	vertexSource.append("uniform mat4 viewMatrix; \n ");
	vertexSource.append("uniform mat4 modelMatrix; \n");
	// uniforms
	
	for(Uniformlist::iterator i= uniformlist.begin(); i != uniformlist.end(); i++)
	{
		vertexSource.append("uniform " + i->type + " " + i->name + ";\n");
	}
	
	vertexSource.append("main() {");
	vertexSource.append("gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4( Position, 1.0 );");
	
	vertexSource.append("}");
	
	fragmentSource.append("  in vec4 frag_color;\
	                         main(){\n\
	                          gl_FragColor = frag_color;\n\
	                         }");
	  
	
	
	shader->SetSource(vertexSource,GL_VERTEX_SHADER);
	shader->SetSource(fragmentSource,GL_FRAGMENT_SHADER);
	shader->Link();
	std::string position = "Position";
	shader->BindAttribLocation(0,position);
	
	return shader;

}

void GL_ShaderManager::MakeFlatShading(std::string& source )
{
	source.append("gl_frag_Color = Color;");
}

void GL_ShaderManager::MakeLambertShading(std::string& source)
{
	source.append("gl_frag_Color");
}


void GL_ShaderManager::MakePhongShading(std::string& source)
{
  
}
