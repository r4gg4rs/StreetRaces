#ifndef STREETRACER_GL_VAO_GROUPOBJECT_H
#define STREETRACER_GL_VAO_GROUPOBJECT_H

#include "../framework/irenderable.h"

namespace SR
{
  class VaoGroupObject : IRenderable
  {
    public:
      VaoGroupObject(Vao* vao);
      ~VaoGroupObject();
  
      void Add(IEntity* entity);
      void Render();
    private:
      Vao*                  p_vao;
      std::vector<IEntity*> p_entitys;
  };
}
#endif