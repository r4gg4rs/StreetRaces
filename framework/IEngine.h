#ifndef SR_IENGINE_H
#define SR_IENGINE_H

namespace SR
{
  typedef float Real;
  
  class IEngine
  {
    public:
      virtual void Initialize()=0;
      virtual void Start()=0;
      virtual void Update(Real dt)=0; 
  };
}
#endif