#include "GL_VAO_Object.h"

using namespace SR;

VaoObject::VaoObject(IEntity* entity, Vao* vao) 
{
  p_entity = entity;
  p_vao = vao;
}

VaoObject::~VaoObject()
{
  
}

void VaoObject::Render()
{
  
}

