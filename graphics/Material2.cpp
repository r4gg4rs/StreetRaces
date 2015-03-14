#include "Material2.h"

using namespace SR;
using namespace T;

Material::Material()
{

}

Material::~Material()
{

}

void Material::Initialize()
{
 	std::string vertexSource = "#version 400\n";
 	std::string fragmentSource = "#version 400\n";
 
 	std::string attributes = "	in vec3 Position; \n \
 															in vec3 Normal; \n ";
	vertexSource.append(attributes);
	
	for(unsigned int i = 0; i< m_uniforms.size(); i++ )
	{
		vertexSource.append( "uniform " + uniforms[i] + ";\n" );
	}
	
	vertexSource.append("main() {");
	
	vertexSource.append("}");
 	
}


void Material::SetColor(const Color& color)
{
	Uniform colorUniform;
	colorUniform.name ="Color";
	colorUniform.type =" vec4";
	colorUniform.value = color;
}

Shader* Material::GetShader()
{
	return p_shader;
}


void Material::Apply()
{
	if(!p_shader) return
	
	p_shader->Bind();
	
	for(unsigned int i=0; i < m_uniforms.size; i++)
	{
		p_shader->SetUniform(	m_uniforms[i].name, m_uniforms[i].value );
	}
		
}
