#include "GL_VAO_GroupObject.h"

using namespace SR;

VaoGroupObject::VaoGroupObject(Vao* vao)
{
  p_vao = vao;
}

VaoGroupObject::~VaoGroupObject()
{
  
}

void VaoGroupObject::Add(IEntity* entity)
{
  p_entitys.push_back(entity);
}

void VaoGroupObject::Render()
{
  
}