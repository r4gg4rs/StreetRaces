#ifndef SR_SCENE_H
#define SR_SCENE_H

namespace SR
{
  class Scene
  {
    public:
      Scene();
      ~Scene();
      
      void Add(IEntity* entity);
      void Add(MeshObject* object); // call RenderingSystem.add(MeshObject)
      
    private:
      std::vector<IEntity*>     m_entitys;
  }
}
#endif