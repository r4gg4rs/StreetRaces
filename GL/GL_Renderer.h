#ifndef SR_GL_RENDERER_H
#define SR_GL_RENDERER_H

#include "../framework/IBuffer.h"
#include "../framework/IRenderer.h"
 #include "../GLUT/GLUT.inc"
#include "Shader.h"
#include "../core/MeshObject.h"
#include "../core/base.inc"


namespace SR
{
  class MeshObject;
  
  typedef std::vector<MeshObject*> MeshObjectList;
  class GL_Renderer : public IRenderer
  {
    private:
      int*          p_view;
    public:
      GL_Renderer();
      ~GL_Renderer();
      virtual void  SetClearColor(Color& color);
      virtual void  Clear();
      virtual void  InitMesh(IMeshPtr mesh);
      virtual void  Render(IMeshPtr mesh);
      virtual void  Render(MeshObject* meshObject);
      virtual void  Render(IMeshPtr mesh, MaterialPtr material, Matrix4 model);
      // virtual void Render(TerrainPiece* terrainPiece); //TODO
      
      virtual void  SetViewport(int xMin, int Ymin, int xMax, int yMax );
      int*          GetViewport();
      Vector3       m_col;
      Shader* p_shader; // testing purpouse
  };
  
//  std::shared_ptr<GL_Renderer> GL_RendererPtr;
}
#endif
