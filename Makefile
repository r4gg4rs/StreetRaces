CC = g++
PROGRAM = streetracer
FLAGS = -Wall
LIBS = -lSDL2 -lGL -lGLU
PLIBS = ./camera/sr_camera.a ./math/sr_math.a ./graphics/sr_graphics.a
SOURCES =  entity.cpp ./gl4/mesh.cpp gameobject.cpp scene.cpp eventmanager.cpp carcontkeyboard.cpp ecar.cpp ./physics/body.cpp ./physics/test/car.cpp ./physics/test/car_body.cpp ./sdl/sdl_app.cpp ./sdl/sdl_eventmanager.cpp 
ALL : $(SOURCES)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) $(PLIBS) -o $(PROGRAM)



