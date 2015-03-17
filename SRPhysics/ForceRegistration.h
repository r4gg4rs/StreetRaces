#ifndef SR_PHYSICS_FORCEREGISTRATION_H
#define SR_PHYSICS_FORCEREGISTRATION_H

namespace SR
{
  
  typedef std::vector<BodyComponent> BodyList;
  class ForceRegistration
  {
    
    public:
    
      ForceGeneratorPtr generator;
      BodyList          bodylist;
      
      void AddBody(BodyComponentPtr body)
      {
        bodylist.push_back(body);
      }
      
      void UpdateForce(Real dt)
      {
        for(unsigned int i=0; i< bodylist.size(); i++)
        {
          generator->UpdateForce(bodylist[i], dt);
        }
      }
  };
}
#endif