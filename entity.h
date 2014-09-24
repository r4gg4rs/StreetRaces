/*
  For testing
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "gameobject.h"
#include "./gl4/mesh.h"
#include "./math/math_inc.h"
#include "renderable.h"
#include "updateable.h"
#include "controllable.h"

class Entity : public GameObject, public IRenderable, public Updateable , public Controllable
{
 public:
  Entity();
  virtual ~Entity();
  void Load();
  void Render(RenderState &state);
  void Update(float dt);
  void SetPosition(const Vector3& pos);

  const Vector3& GetPosition() const;
  virtual std::string Type() const;

 protected:
  Vector3 m_Position;
  Mesh* p_mesh;
  float m_angle;
  Vector3 m_heading;
};
#endif
