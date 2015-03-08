#include "sdl_app.h"
#include "sdl_config.def"


SdlApp::SdlApp()
{
	title="testi";
	m_runing =false;
  p_eventManager = SdlEventManager::GetSingletonPtr();
  m_prevTime = 0;
  screen_pos_x = 100;
	screen_pos_y = 100;
	screen_width = 800;
	screen_height = 400;
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
	
	
	p_scene = new Scene();// SceneManager::GetSingleton().GetScene();
	p_scene->Initialize();
 
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	
	p_window = SDL_CreateWindow(title.c_str(),screen_pos_x,screen_pos_y,screen_width,screen_height, SDL_WINDOW_OPENGL);
	m_context = SDL_GL_CreateContext(p_window);
	
	m_runing = true;
	
	SDL_Event event;
        glViewport(0,0,screen_width,screen_height);
	while(m_runing)
	{
		p_eventManager->Update();
		Update();
    Render();
		
	}
}

void SdlApp::Stop()
{
  m_runing = false;
}

void SdlApp::Shutdown()
{
	delete p_scene;
	SDL_GL_DeleteContext(m_context);
	SDL_Quit();
}

void SdlApp::Render() 
{
  glClear(GL_COLOR_BUFFER_BIT);
  
    /*
  glBegin(GL_LINES);
  glVertex2f(-0.2f,0.0f);
  glVertex2f( 0.2f,0.0f);
  glEnd();
 */
  p_scene->Render();
  SDL_GL_SwapWindow(p_window);
}

void SdlApp::Update()
{
  Uint32 time = SDL_GetTicks();
  float dt = (float)time - (float) m_prevTime;
  m_prevTime = time;
	p_scene->Update(dt);
}



