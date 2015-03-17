#ifndef SR_GRAPHICS_SKELETONNODE_H
#define SR_GRAPHICS_SKELETONNODE_H

namespace SR
{
  
  class SkeletonNode
  {
    private:
      typedef std::shared_ptr<SkeletonNode> SkeletonNodePtr
      typedef std::vector<SkeletonNodePtr> SkeletonNodeList;
      
      
      SkeletonNodeList  m_childrens;
      SkeletonPtr       p_parent
      Index             m_firstIndex;
      Index             m_lastIndex;
      Index             m_parentIndex;
      
      Real              m_tx;
      Real              m_ty;
      Real              m_tz;
      
      Real              m_angleX;
      Real              m_angleY;
      Real              m_angleZ;
      
      Matrix4           m_matrix;
      
    public:
      SkeletonNode(Index parentIndex, Real tx, Real ty, Real tz, Index firsIndex, Index lastIndex)
      :p_parent(NULL),m_parentIndex(parentIndex), m_tx(tx), m_ty(ty), m_tz(tz),
      m_firstIndex(firstIndex),m_lastIndex(lastIndex)
      {
        m_matrix = new Matrix4();
      }
      ~SkeletonNode(){}
      
      void Add(SkeletonNodePtr skeleton)
      {
        m_childrens.push_back(skeleton);
      }
      
      void Remove(SkeletonNodePtr skeleton)
      {
        
      }
      
      void RotateX(Real angle)
      {
        
      }
      
      void RotateY(Real angle)
      {
        
      }
      
      void RotateZ(Real angle)
      {
        
      }
    
        
  };
}

#endif