#ifndef SR_PHYSICS_FORCEREGISTRY_H
#define SR_PHYSICS_FORCEREGISTRY_H

namespace SR
{
  struct FG_Body
  {
    ForceGeneratorPTr   generator;
    BodyPtr             body;
  };
  
  typedef std::vector<FG_Body> Registry;
  typedef unsigned int Index;
  
  class ForceRegistry
  {
      private:
        Registry registry;
      public:
        void        Add     (ForceGeneratorPtr forceGen, BodyPtr body);
        void        Remove  (ForceGeneratorPtr forceGen, BodyPtr body);
        void        Clear   ();
        void        Update  (Real dt);
  };
}
#endif