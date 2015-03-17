#ifndef SR_GRAPHICS_SKELETON_H
#define SR_GRAPHICS_SKELETON_H

namespace SR
{
  class Skeleton
  {
    typedef std::vector<SkeletonNodePtr> BoneList;
    
    private:
      SkeletonNodePtr p_root;
      BoneList        m_bones;  
    public:
      Skeleton(){}
      ~Skeleton(){}
      
      SkeletonNodePtr GetRoot()
      {
        return p_root;
      }
      
  };
}
#endif