#ifndef SR_IRENDERER_H
#define SR_IRENDERER_H

#include "../graphics/Mesh.h"
#include "../graphics/Material2.h"
#include "../core/Color.h"
#include "ICamera.h"
#include "../core/NodeObject.h"
#include "../core/MeshObject.h"
#include <memory>

namespace SR
{
  class MeshObject;
  
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
      virtual void    InitMesh(IMeshPtr mesh)=0;
      virtual void    Render(IMeshPtr mesh)=0; // TODO make nesessary virtual function in IMesh and put it here 
                                              // TODO buffers in imesh
      virtual void    Render(MeshObject* object)=0; // TODO correct IMeshObject and change it here
      
      virtual void    Render(IMeshPtr mesh, MaterialPtr material, Matrix4 model)=0;  // Matrix
      virtual void    SetViewport(int xMin, int yMin, int Xmax, int Ymax)=0;
      virtual int*    GetViewport()=0;

  };
  
  typedef std::shared_ptr<IRenderer> IRendererPtr;
}
#endif