#include "GL_ShaderManager.h"

using namespace SR;


GL_ShaderManager::GL_ShaderManager()
{

}

GL_ShaderManager::~GL_ShaderManager()
{

}

Shader* GL_ShaderManager::MakeShader( Attributelist& attributelist, Uniformlist& uniformlist, MaterialType materialtype)
{
	Shader* shader = new Shader();
	std::string vertexSource = "#vertion 400 \n ";
	std::string fragmentSource = "#version 400 \n";
	
	
	// Attributes
	for(Attributelist::const iterator i= attributelist.begin(); i != attributelist.end(); i++) 
	{
		vertexSource.append("in " + i->type + " " + i->name + ";\n";
	}
	
	// TODO out
	vertexSource.append(" out vec4 frag_color;");
	
	
	vertexSource.append("		uniform mat4 projectionMatrix; \n \
													uniform mat4 viewMatrix; \n \
													uniform mat4 modelMatrix; \n";
	// uniforms
	
	for(Uniformlist::const iterator i= uniformlist.begin(); i != uniformlist.end(); i++)
	{
		vertexSource.append("uniform " + i->type + " " + i->name + ";\n";
	}
	
	vertexSource.append("main() {");
	vertexSource.append("gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4( Position, 1.0 );");
	
	vertexSource.append("}");
	
	
	
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
