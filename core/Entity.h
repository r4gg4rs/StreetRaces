#ifndef STREETRACER_ENTITY_H
#define STREETRACER_ENTITY_H

#include "base.inc"
#include "../framework/IEntity.h"


namespace SR
{
  class Entity : public IEntity
  {
    public:
      Entity();
      ~Entity();
      
      void AddChild(IEntity *entity);
      void SetParent(IEntity* entity);
      
    protected:
      unsigned int            m_id;
      std::vector<IEntity*>   m_childs;
      IEntity*                p_parent;
  };
}
#endif