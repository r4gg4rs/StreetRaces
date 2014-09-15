#include "gameobject.h"

const Rtti GameObject::s_type

int GameObject::s_nextID = 1;


GameObject::Gameobject()
{

}

GameObject::~GameObject()
{

}

int GameObject::GetID() const
{
  return m_ID;
}

void GameObject::SetTag(std::string tag)
{
  m_tag = tag;
}

const Rtti GetType()
{
  return TYPE;
}
