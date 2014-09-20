/*
  For testing
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "gameobject.h"
#include "./gl4/mesh.h"
#include "./math/math_inc.h"
class Entity : public GameObject
{
 public:
  Entity();
  ~Entity();
  void Load();
  void Render();
  void SetPosition(const Vector3& pos);
  const Vector3& GetPosition() const;
  virtual std::string Type() const;
 private:
  Vector3 m_position;
  Mesh* p_mesh;
};
#endif
