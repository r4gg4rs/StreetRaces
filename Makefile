CC = g++
PROGRAM = streetracer
FLAGS = -Wall
LIBS = -lSDL2 -lGL -lGLU
SOURCES = ./sdl/sdl_app.cpp entity.cpp ./gl4/mesh.cpp gameobject.cpp scene.cpp ./math/math.cpp ./math/vec_alg.cpp ./camera/camera_base.cpp eventmanager.cpp ./sdl/sdl_eventmanager.cpp carcontkeyboard.cpp ecar.cpp ./physics/body.cpp ./physics/test/car.cpp ./physics/test/car_body.cpp
ALL : $(SOURCES)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) -o $(PROGRAM)



