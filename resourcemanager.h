#ifndef STREETRACER_RESOURCEMANAGER_H
#define STREETRACER_RESOURCEMANAGER_H

class IResource
{
 public:
  virtual ~IResource(){};
  virtual void Load(std::string& filename);  
};
#endif
