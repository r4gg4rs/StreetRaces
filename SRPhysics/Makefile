CC = g++
PROGRAM = physics
FLAGS = -Wall -std=c++11
LIBS = -lGL -lGLU -lglut -lGLEW

SOURCES = main.cpp\
	../GLUT/GLUT_Window.cpp\
	../core/Component.cpp\
	../SRPhysics/PhysicsEngine.cpp ../SRPhysics/ForceRegistry.cpp 

ALL : $(SOURCES)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) $(PLIBS) -o $(PROGRAM)



