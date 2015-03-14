#ifndef SR_IMESH_H
#define SR_IMESH_H

#include "../math/math.inc"
#include "../core/base.inc"
#include "../core/Color.h"
#include "IBuffer.h"


namespace SR
{
  typedef Vector3                   Vertex;
  typedef Vector3                   Normal;
  typedef Vector2                   TextCoord;
  typedef unsigned int              Index;
  typedef std::vector<Vertex>       Vertices;
  typedef std::vector<Color>        Colors;
  typedef std::vector<Normal>       Normals;
  typedef std::vector<TextCoord>    TextCoords;
  typedef std::vector<Index>        Indices;
 
 
  
  class RenderState
  {
    public:
      Matrix4*    m_viewMatrix;
      Matrix4*    m_projectionMatrix;
      Matrix4*    m_modelMatrix;
  };
  
  class IMesh
  {
    public:
      virtual Vertices&                   GetVertices()=0;
    //  virtual TextCoords&                 GetTextCoord()=0;
      virtual Indices&                    GetIndices()=0;
      virtual void                        Render(RenderState& state)=0;
      virtual void                        Render()=0;
      virtual unsigned int                GetSize()=0;
      virtual void                        AddBuffer(IBuffer* buffer)=0;
    
  };
}

#endif
