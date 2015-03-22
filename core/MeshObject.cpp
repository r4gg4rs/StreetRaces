
#include "MeshObject.h"
#include <iostream>

using namespace SR;

MeshObject::MeshObject()// :p_mesh(NULL), m_isVisible(true), m_needsToRender(true)
{
  m_matrixNeedsToUpdate = true;
}

MeshObject::~MeshObject()
{
  
}

/*
void MeshObject::Add(MeshObject* mo ) 
{
	m_MOchilds.push_back(mo);
}
*/

void MeshObject::AddComponent(std::string& name, ComponentPtr component)
{
  
  m_components[name] = component;
  component->p_owner = shared_from_this();
 // component->p_parent = shared_from_this();
}


ComponentPtr MeshObject::GetComponent(std::string& name)
{
  return m_components[name];
}

/*
void MeshObject::SetPosition(const Vector3& position)
{
  m_position = position;
  m_matrixNeedsToUpdate = true;
}
*/
void MeshObject::Move(const Vector3& pos)
{
	m_position += pos;
	m_matrixNeedsToUpdate = true;
}
/*
Vector3& MeshObject::GetPosition()
{
  return m_position;
}
*/

void MeshObject::SetRotation(const Vector3& axis, Real angle)
{
	m_rotation.Set(axis,angle);
	m_matrixNeedsToUpdate = true;
}

Quaternion& MeshObject::GetRotation()
{
	return m_rotation;
}


void MeshObject::Rotate(const Vector3& axis, Real angle)
{
	Quaternion rot;
	rot.Set(axis, angle);
	m_rotation *= rot;
	

	Vector3 r;
	r.x = axis.x * angle;
	r.y = axis.y * angle;
	r.z = axis.z * angle;
	
	
	euler += r;
	//m_rotation += rot;
	
	m_matrixNeedsToUpdate = true;
}


void MeshObject::SetMesh(IMeshPtr mesh)
{
  p_mesh = mesh;
  m_needsToRender = p_mesh != NULL;
}

IMeshPtr MeshObject::GetMesh()
{
  return p_mesh;
}

void MeshObject::SetMaterial(MaterialPtr material)
{
  p_material = material;
}


MaterialPtr MeshObject::GetMaterial()
{
  return p_material;
}
/*
Matrix4& MeshObject::GetModelMatrix()
{
  if(m_matrixNeedsToUpdate) UpdateMatrix();
  return m_modelMatrix;
  
}

void MeshObject::UpdateMatrix()
{
  // TODO
  
 // std::cout << "Update matrix " << std::endl;
 // std::cout << "Quat x " << m_rotation.x << " Y " << m_rotation.y << " z " << m_rotation.z << " w " << m_rotation.w << std::endl;
  Matrix4 translation;
  translation.MakeTranslation(m_position);

 	Matrix4 rotation;
 	rotation.MakeRotation(m_rotation);
  
  Matrix4 rotX;
  rotX.MakeRotationX(euler.x);
  
  Matrix4 rotY;
  rotY.MakeRotationY(euler.y);
  
  Matrix4 rotZ;
  rotZ.MakeRotationZ(euler.z);
  
  
	Matrix4 euler = rotX * rotY * rotZ;  
  
  m_modelMatrix = translation * euler; // * rotation;
}
*/
void MeshObject::Render(const ICamera& camera)
{
  
}


void MeshObject::Render() // is this nesassery?
{
  if(m_isVisible && m_needsToRender) // do this need check if p_mesh != null?
  {
    
  }
}


void MeshObject::Render(IRendererPtr renderer)
{
  if(m_isVisible && m_needsToRender)
  {
    
  }
  if( p_mesh != NULL && p_material != NULL)
  {
    renderer->Render(p_mesh, p_material, GetModelMatrix());
  }
}


/*
void MeshObject::SetVisibility(bool value)
{
  m_isVisible = value;
}
*/
void MeshObject::_SetNeedsToRender(bool value)
{
  m_needsToRender = value;
}

bool MeshObject::NeedsToRender()
{
  return (m_isVisible && m_needsToRender);
}

void MeshObject::Render(IRenderer* renderer)
{
//  renderer->Render(*this);  
}


void MeshObject::Print()
{
  std::cout << "MeshObject " <<  GetID() << std::endl; 
}
