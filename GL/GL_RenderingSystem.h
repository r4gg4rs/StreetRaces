/**
 * @author      Jani Haippo
 * @version     03.2015
 * */
 
 #ifndef STREETRACER_GL_RENDERINGSYSTEM_H
 #define STREETRACER_GL_RENDERINGSYSTEM_H
 
 #include "../framework/RenderingSystem.h"
 #include "../framework/IRenderable.h"
 #include "../core/base.inc"
 
 namespace SR
 {
   class GL_RenderingSystem : public RenderingSystem
   {
    public:
      GL_RenderingSystem();
      ~GL_RenderingSystem();
      
     // void Add(IMesh* mesh);
     
      void Add(IMeshObject* obj);

      void Render();
      void Render(std::vector<unsigned int>& render list);

    private:
      std::vector<IRenderable*>   m_renderables; // for testing purpouse 
                                                 // not sure how rendering should make
   };
 }
 #endif