#ifndef STREETRACER_ENTITY_H
#define STREETRACER_ENTITY_H

namespace SR
{
  class Entity : public IEntity
  {
    public:
      Entity();
      ~Entity();
      void AddChild(IEntity *entity);
      
      std::vector<IEntity>  m_childs;
  }
}
#endif