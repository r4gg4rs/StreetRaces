#include "./sdl/sdl_app.h"

int main(int argc, char** argv)
{
	SdlApp* app = SdlApp::GetSingletonPtr();
        //        app->Start();
	
	SdlApp::Delete();
	return 0;	
}
