#ifndef SR_SCENE_V2_H
#define SR_SCENE_V2_H

#include "../framework/IRenderer.h"
#include "../framework/IScene.h"
#include "../core/base.inc"
/*
  Scene graph scene
*/
namespace SR
{
  class Scene : public NodeObject , public IScene
  {
    public:
      Scene();
      ~Scene();
      void InitMeshes(IRendererPtr renderer);
      void Render(IRendererPtr renderer);
  };
  
  typedef std::shared_ptr<Scene> ScenePtr;
}
#endif