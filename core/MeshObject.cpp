
#include "MeshObject.h"

using namespace SR;

MeshObject::MeshObject()
{
  
}

MeshObject::~MeshObject()
{
  
}

void MeshObject::SetPosition(const Vector3& position)
{
  m_position = position;
  m_matrixNeedsToUpdate = true;
}

Vector3& MeshObject::GetPosition()
{
  return m_position;
}

void MeshObject::SetMesh(IMesh* mesh)
{
  p_mesh = mesh;
}

IMesh* MeshObject::GetMesh()
{
  return p_mesh;
}

Matrix4& MeshObject::GetModelMatrix()
{
  if(m_matrixNeedsToUpdate) UpdateMatrix();
  return m_modelMatrix;
}

void MeshObject::UpdateMatrix()
{
  // TODO
}



