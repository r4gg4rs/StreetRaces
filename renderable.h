#ifndef STREETRACER_RENDERABLE_H
#define STREETRACER_RENDERABLE_H

#include "./camera/icamera.h"

class Renderable 
{
 public:
  virtual void Render(const ICamera* camera)=0;
};
#endif
