#ifndef STREETRACER_RENDERABLE_H
#define STREETRACER_RENDERABLE_H

#include "./camera/icamera.h"
#include "./math/math_inc.h"

struct RenderState
{
  Matrix4 ViewMatrix;
  Matrix4 ProjectionMatrix;
  Matrix4 ModelMatrix;
};

/*
  For entity
*/
class IRenderable
{
 public:
  virtual void Render(RenderState& state)=0;
};

class Renderable 
{
 public:
  virtual void Render(const ICamera* camera)=0;
};
#endif
