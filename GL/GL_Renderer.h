#ifndef SR_GL_RENDERER_H
#define SR_GL_RENDERER_H

#include "../framework/IBuffer.h"
#include "../framework/IRenderer.h"
 #include "../GLUT/GLUT.inc"
#include "Shader.h"

namespace SR
{
  class GL_Renderer : public IRenderer
  {
    private:
      int*          p_view;
    public:
      GL_Renderer();
      ~GL_Renderer();
      virtual void  SetClearColor(Color& color);
      virtual void  Clear();
      virtual void  InitMesh(IMesh* mesh);
      virtual void  Render(IMesh* mesh);
      virtual void  Render(MeshObject* meshObject);
      // virtual void Render(TerrainPiece* terrainPiece); //TODO
      
      virtual void  SetViewport(int xMin, int Ymin, int xMax, int yMax );
      int*          GetViewport();
      Vector3       m_col;
      Shader* p_shader; // testing purpouse
  };
}
#endif
