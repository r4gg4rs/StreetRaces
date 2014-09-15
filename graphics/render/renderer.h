#ifndef STREETRACER_RENDERER_H
#define STREETRACER_RENDERER_H

class Renderer
{
 public:
  virtual ~Renderer();
  void SetCamera(ICamera* camera);
  ICamera* GetCamera() const;
};
#endif
