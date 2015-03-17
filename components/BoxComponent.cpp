#include "BoxComponent.h"

BoxComponent::BoxComponent()
{
  p_points = new Vector3[8];
  p_points[0] = Vector3()
  
}

BoxComponent::~BoxComponent()
{
  
}

void BoxComponent::Set(const Vector3& min, const Vector3& max)
{
  m_min = min;
  m_max = max;
}

void BoxComponent::Update()
{
  Matrix4 modelMatrix = p_owner->GetModelMatrix();
  Vector3 trans_min = modelMatrix * m_min;
  Vector3 trans_max = modelMatrix * m_max;
  m_min = Vector3.Min(trans_min, trans_max);
  m_max = Vector3.Max(trans_max, trans_min);
}
