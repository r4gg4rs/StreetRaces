CC = g++
PROGRAM = streetracer
FLAGS = -Wall
LIBS = -lSDL2 -lGL -lGLU
SOURCES = ./sdl/sdl_app.cpp entity.cpp ./gl4/mesh.cpp gameobject.cpp scene.cpp
 
ALL : $(SOURCES)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) -o $(PROGRAM)



