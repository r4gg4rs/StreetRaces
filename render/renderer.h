#ifndef SR_RENDERER_H
#define SR_RENDERER_H

class Renderer
{
 public:
  Renderer();
  ~Renderer();

  virtual void Render()=0;
};

class GL2MeshRenderer
{
 public:
  Gl2MeshRenderer();
  ~GL2MeshRenderer();

  virtual void Render(Renderable* renderable);
}
#endif
