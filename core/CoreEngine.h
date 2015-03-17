/**
* @author			Jani Haippo
* @version		03.2015
**/

#ifndef STREETRACER_COREENGINE_H
#define STREETRACER_COREENGINE_H

//#include "../framework/RenderingSystem.h"
#include "../framework/IScene.h"
#include "../framework/ICamera.h"
#include "../framework/IRenderer.h"

#include "../utils/singleton.h"

namespace SR
{
	class CoreEngine : public Singleton<CoreEngine> 
	{
		public:
			CoreEngine();
			~CoreEngine();
      //initialize(std::string filename)
      //initialize(stream)
		//	void        SetScene(IScene* scene);
			void        SetScene(IScenePtr scene);
			IScenePtr   GetScene();
	  	void        SetRenderer(IRendererPtr renderer);
	  	IRenderer*  GetRenderer();
	  	void        Start();
			void        Update();
			void        Render();
			
		private:
      IScenePtr           p_scene;
		  IRendererPtr        p_renderer;
	};
  typedef std::shared_ptr<CoreEngine> CoreEnginePtr;
};

#endif
