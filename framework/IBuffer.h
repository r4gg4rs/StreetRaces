/**
 * @author    Jani Haippo
 * @version   03.2015
 * @file      IBuffer
 * */

#ifndef STREETRACER_IBUFFER_H
#define STREETRACER_IBUFFER_H

namespace SR
{
  class IBuffer
  {
    public:
      virtual void Bind()=0;
  };
}
#endif