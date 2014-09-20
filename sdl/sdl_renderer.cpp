#include "sdl_renderer.h"

SdlRender::SdlRenderer()
{
  if(TTF_WasInit ==0)
    {
      TTF_Init();
    } 
}

SdlRender::~SdlRenderer()
{
  TTF_Quit();
}

void SdlRenderer::RenderText(const std::string& text, const Vector2& position, const Color4& fg, const Color4& bg)
{

}  
