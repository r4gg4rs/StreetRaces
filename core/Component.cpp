
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


ID Component::GetID()
{
	return s_nextID++;
}


