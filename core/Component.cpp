
#include "Component.h"
using namespace SR;

ID Component::s_nextID = 1;

Component::Component() : m_id( GetID() )
{

}

Component::~Component()
{

}
/*
void Component::SetParent(MeshObjectPtr parent) 
{
	p_parent = parent;
}
*/

void Component::SetType(std::string& type)
{
	m_type = type;
}

void Component::SetOwner(MeshObjectPtr owner)
{
  p_owner = owner;
}
/*
void Component::AddListener(CEventType event, EventFunc callback)
{
  ComponentListener listener;
  listener.event = event;
  listener.callback = callback;
}
*/

ID Component::GetID()
{
	return s_nextID++;
}


