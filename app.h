#ifmdef STREETRACER_APP_H
#define STREETRACER_APP_H

class App
{
 public:
  virtual void Initialize() =0;
  virtual void Start()=0;
  virtual void Shutdown()=0;
};
#endif
