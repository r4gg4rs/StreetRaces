#ifndef SR_GROUP_H
#define SR_GROUP_H

#include "../math/math.inc"
#include "../core/base.inc"

namespace SR
{
  typedef Vector3 Euler;
  class Group 
  {
    typedef std::shared_ptr<Group> GroupPtr;
    typedef std::list<GroupPtr> GroupList;
    
    protected:
      GroupList     m_childrens;
      GroupPtr      p_parent;
      Vector3       m_position;
      Euler         m_rotation;
    public:
      Group();
      ~Group();
      
      void      Add     (GroupPtr child);
      void      Remove  (GroupPtr child);
      
      
  };
}

#endif