#include "Material2.h"

using namespace SR;


Material::Material()
{

}


Material::~Material()
{

}
void Material::AddUniform(const Uniform& uniform)
{
  m_uniforms.push_back(uniform);
}

void Material::Initialize()
{
  /*
 	std::string vertexSource = "#version 400\n";
 	std::string fragmentSource = "#version 400\n";
 
 	std::string attributes = "	in vec3 Position; \n \
 															in vec3 Normal; \n ";
	vertexSource.append(attributes);
	
	for(unsigned int i = 0; i< m_uniforms.size(); i++ )
	{
	 std::string line ="uniform " + m_uniforms[i].type + " " + m_uniforms[i].name + ";\n";
		vertexSource.append(line  );
	}
	
	vertexSource.append("main() {");
	
	vertexSource.append("}");
 	*/
}

void Material::Initialize(IMeshPtr mesh)
{
  
}

void Material::SetColor(const Color& color)
{
	Uniform colorUniform;
	colorUniform.name ="Color";
	colorUniform.type =" vec4";
	colorUniform.value = color;
}

ShaderPtr Material::GetShader()
{
	return p_shader;
}


void Material::Apply()
{
	if(!p_shader) return
	
	p_shader->Bind();
	
	for(unsigned int i=0; i < m_uniforms.size(); i++)
	{
		p_shader->SetUniform(	m_uniforms[i].name.c_str(), m_uniforms[i].value );
	}
		
}
