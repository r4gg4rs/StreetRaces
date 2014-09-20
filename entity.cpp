#include "entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::Load()
{
  p_mesh = new Mesh();
}

void Entity::Render()
{
  p_mesh->Render();
}

void Entity::SetPosition(const Vector3& pos)
{
  m_position = pos;
}

const Vector3& Entity::GetPosition() const
{
  return m_position;
}

std::string Entity::Type() const
{
  return "Entity";
}
