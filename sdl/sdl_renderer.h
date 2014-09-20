#ifndef STREETRACER_SDL_RENDERER_H
#define STREETRACER_SDL_RENDERER_H

#include "../math/math_inc.h"

class SdlRenderer
{
 public:
  SdlRenderer();
  ~SdlRenderer();

  void RenderText(const std::string& text,const Vector2& position,const Color4& fg, Color4& bg);

 private:
  TTF_Font* font;
#endif
