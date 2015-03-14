#ifndef SR_IMESHOBJECTVISITOR_H
#define SR_IMESHOBJECTVISITOR_H

#include "IMeshObject.h"

namespace SR
{
  class IMeshObjectVisitor
  {
    public:
      virtual void Visit(IMeshObject* meshobject);
  };
}
#endif