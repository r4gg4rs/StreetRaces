/*
  @author  : r4gg4rs r4gg4rs@yahoo.com
  @version : 18.09.2014
*/

#ifndef STREETRACER_RENDERABLEOBJECT_H
#define STREETRACER_RENDERABLEOBJECT_H

#include "gameobject.h"
#include "rendable.h"
#include "./gl4/model.h"

class RenderableObject : public GameObject
{
 public:
  RenderableObject();
  ~RenderableObject();
  void Render(const ICamera* camera);
 private:
  Model* p_model;
};
#endif
