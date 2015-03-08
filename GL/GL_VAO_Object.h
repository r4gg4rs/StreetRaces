/**
 * @author    Jani Haippo
 * @version   03.2015
 * */
 
 #ifndef STREETRACER_GL_VAO_OBJECT_H
 #define STREETRACER_GL_VAO_OBJECT_H
 
 #include "../framework/irenderable.h"
 
 namespace SR
 {
   class VaoObject :IRenderable
   {
    public:
      VaoObject(IEntity* object, Vao* vao);
      ~VaoObject();
      
      void Render();
        
    private:
      IEntity*  p_object;
      Vao*      p_vao;
      
   };
 }
 #endif