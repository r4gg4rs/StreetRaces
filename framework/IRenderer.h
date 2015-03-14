#ifndef SR_IRENDERER_H
#define SR_IRENDERER_H

#include "../graphics/Mesh.h"
#include "../core/Color.h"
#include "ICamera.h"
#include "../core/MeshObject.h"

namespace SR
{
  class IRenderer
  {
    protected:
      Color       m_clearColor;
      ICamera*    p_camera;
    public:
      
    /*
      void  SetClearColor(Color& clearColor)
      {
        m_clearColor = clearColor;
      }
      */
      
      void  SetCamera(ICamera* camera)
      {
        p_camera = camera;
      }
      
      virtual void    SetClearColor(Color& clearColor)=0;
      virtual void    Clear()=0;
      virtual void    InitMesh(IMesh* mesh)=0;
      virtual void    Render(IMesh* mesh)=0; // TODO make nesessary virtual function in IMesh and put it here 
                                              // TODO buffers in imesh
      virtual void    Render(MeshObject* object)=0; // TODO correct IMeshObject and change it here
      virtual void    SetViewport(int xMin, int yMin, int Xmax, int Ymax)=0;
      virtual int*    GetViewport()=0;

  };
}
#endif