#ifndef SR_COLLISION_SPHERE_H
#define SR_COLLISION_SPHERE_H

#include "../../math/math_inc.h"

class Sphere
{
 public:
  Sphere();
  ~Sphere();

void SetPosition(const Vector3& position);
const Vector3& GetPosition() const;

void SetRadius(float radius);
float GetRadius() const;
 private:
  Vector3 m_position;
  float   m_radius;
};
#endif
