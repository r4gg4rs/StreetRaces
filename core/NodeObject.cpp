#include "NodeObject.h"
#include <iostream>

using namespace SR;

ID NodeObject::s_nextID =1;

NodeObject::NodeObject() : m_modelMatrix(Matrix4()), m_position(Vector3(0.0,0.0,0.0)),
m_erotation(Euler()), m_matrixNeedsToUpdate(true)
{
  m_id = s_nextID++;
  p_parent = NULL;
  
}

NodeObject::~NodeObject()
{
  
}


bool NodeObject::operator ==(const NodeObjectPtr obj)
{
  return m_id == obj->GetID();
}


ID  NodeObject::GetID() const
{
  return m_id;
}


void NodeObject::Add(NodeObjectPtr child)
{
  m_childs.push_back( child);
}


void NodeObject::Remove(NodeObjectPtr child)
{
  m_childs.remove(child);
}


void NodeObject::SetParent(NodeObjectPtr parent)
{
  p_parent = parent;
}


std::shared_ptr<NodeObject> NodeObject::GetParent   ()
{
  return p_parent;
}


void NodeObject::SetPosition(const Vector3& position)
{
  m_position = position;
}


Vector3& NodeObject::GetPosition()
{
  return m_position;
}


void NodeObject::SetRotation(const Euler& rotation)
{
  m_erotation = rotation;
}


Euler& NodeObject::GetRotation()
{
  return m_erotation;
}


Matrix4& NodeObject::GetModelMatrix()
{
  if(m_matrixNeedsToUpdate) UpdateMatrix();
  return m_modelMatrix;
}

Matrix4& NodeObject::GetToWorld()
{
  if(ToWorldMatrixNeedsToUpate() ) UpdateToWorldMatrix();
  return m_toWorld;
}

void NodeObject::UpdateToWorldMatrix()
{
  if(m_matrixNeedsToUpdate) UpdateMatrix();
  if(p_parent) 
  {
    p_parent->UpdateToWorldMatrix();
    m_toWorld = p_parent->GetToWorld() * m_modelMatrix;
  }
  else m_toWorld = m_modelMatrix;
}

void NodeObject::UpdateMatrix()
{
  Matrix4 translation;
  translation.MakeTranslation(m_position);
/*
 	Matrix4 rotation;
 	rotation.MakeRotation(m_rotation);
  */
  Matrix4 rotX;
  rotX.MakeRotationX(m_erotation.x);
  
  Matrix4 rotY;
  rotY.MakeRotationY(m_erotation.y);
  
  Matrix4 rotZ;
  rotZ.MakeRotationZ(m_erotation.z);
  
  
	Matrix4 euler = rotX * rotY * rotZ;  
  
  m_modelMatrix = translation * euler; // * rotation;
}

bool NodeObject::ToWorldMatrixNeedsToUpate()
{
  if(p_parent != NULL) return p_parent->ToWorldMatrixNeedsToUpate() && m_matrixNeedsToUpdate;
  return m_matrixNeedsToUpdate;
}

bool NodeObject::MatrixNeedsToUpdate()
{
  return m_matrixNeedsToUpdate;
}


void NodeObject::Render(IRendererPtr renderer)
{
  for(ChildList::iterator it=m_childs.begin(); it != m_childs.end(); ++it)
  {
    // it->Render(renderer); // not work. why?
    it->get()->Render(renderer);
  }
}

bool NodeObject::IsVisible() const
{
  return m_isVisible;
}

void NodeObject::SetVisibility(bool visibility)
{
  m_isVisible = visibility;
}

void NodeObject::Print()
{
  std::cout << "ID " << m_id <<std::endl;
}
