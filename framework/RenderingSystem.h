#ifndef SR_RENDERING_SYSTEM_H
#define SR_RENDERING_SYSTEM_H

#include "IMeshObject.h"

namespace SR
{
  class RenderingSystem
  {
    public:
      virtual void Add(IMeshObject* meshobject)=0;
      virtual void Render(Scene* scene)=0;
    protected:
      Renderer*   p_renderer;
  };
}
#endif