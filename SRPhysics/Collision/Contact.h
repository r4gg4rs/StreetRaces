#ifndef SRPHYSICS_CONTACT_H
#define SRPHYSICS_CONTACT_H

namespace SR
{
  class Contact
  {
    public:
      BodyPtr     body[2];
      Vector3     contactNormal;
      Real        penetration;
  };
}

#endif