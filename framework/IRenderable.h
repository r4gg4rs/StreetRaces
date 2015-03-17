#ifndef STREETRACER_IRENDERABLE_H
#define STREETRACER_IRENDERABLE_H

#include "IRenderer.h"

namespace SR
{
  class IRenderable
  {
    public:
      virtual void Render(IRendererPtr renderer)=0;
  };
}
#endif