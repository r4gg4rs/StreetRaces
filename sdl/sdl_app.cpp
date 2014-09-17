#include "sdl_app.h"
#include "sdl_config.def"
SdlApp::SdlApp()
{
	title="testi";
	m_runing =false;
}

SdlApp::~SdlApp()
{

}

SdlApp* SdlApp::GetSingletonPtr()
{
  static SdlApp* instance;
  if(instance == NULL)
    {
      instance = new SdlApp();
      instance->Start();
    }
  return instance;
}


SdlApp& SdlApp::GetSingleton()
{
  return *GetSingletonPtr();
}

void SdlApp::Delete()
{
  static SdlApp* app;
  app->Shutdown();
  delete app;
}

void SdlApp::Start()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	
	p_window = SDL_CreateWindow(title.c_str(),screen_pos_x,screen_pos_y,screen_width,screen_height, SDL_WINDOW_OPENGL);
	m_context = SDL_GL_CreateContext(p_window);
	
	m_runing = true;
	
	SDL_Event event;
	
	while(m_runing)
	{
		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)break;// m_runing =  false;
			if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE) m_runing = false;
		}
		
		
		SDL_GL_SwapWindow(p_window);
	}
}

void SdlApp::Shutdown()
{
	SDL_GL_DeleteContext(m_context);
	SDL_Quit();
}



int main(int argc, char** argv)
{
	SdlApp* app = SdlApp::GetSingletonPtr();
	
	SdlApp::Delete();
	return 0;	
}
