sr_sdl.a : sdl_app.o sdl_eventmanager.o
	ar rcs sr_sdl.a sdl_app.o sdl_eventmanager.o 
	
sdl_app.o : sdl_app.cpp
	g++ -Wall -c sdl_app.cpp -lSDL2 -lGL
	
sdl_evenmanager.o : sdl_eventmanager.cpp
	g++ -Wall -c sdl_eventmanager.cpp
