
#include "Entity.h"

using namespace SR;

Entity::Entity()
{
  
}

Entity::~Entity()
{
  
}

void Entity::AddChild(IEntity* entity)
{
  m_childs.push_back(entity);
}


