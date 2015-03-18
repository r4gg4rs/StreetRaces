#ifndef SR_PHYSICS_CONTACT_H
#define SR_PHYSICS_CONTACT_H

namespace SR
{
  class Contact
  {
    public:
      BodyPtr 	bodys[2];
      Vector3		ContactPoint;
      Vector3		Normal;
  };
}
#endif
