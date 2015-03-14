#ifndef SR_SCENE_H
#define SR_SCENE_H

#include "base.inc"
#include "MeshObject.h"
#include "../framework/IRenderer.h"
#include "../framework/IScene.h"

namespace SR
{
  class Scene : public IScene
  {
    public:
      Scene();
      ~Scene();
      
     // void Add(IEntity* entity);
      void Add(MeshObject* object); // call RenderingSystem.add(MeshObject)
      void Render(IRenderer* renderer);
      void InitMeshes(IRenderer* renderer);
    //  void Visit(IMeshObjectVisitor& visitor);
    private:
   //   std::vector<IEntity*>     m_entitys;
      std::vector<MeshObject*>  m_meshObjects; 
  };
}
#endif