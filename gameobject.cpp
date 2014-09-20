#include "gameobject.h"

/*
const Rtti GameObject::s_type
*/
int GameObject::s_nextID = 1;


GameObject::GameObject()
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

std::string GameObject::Type() const
{
  return "GameObject";
}

/*
const Rtti GetType()
{
  return TYPE;
}
*/
