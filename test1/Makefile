CC = g++
PROGRAM = run
FLAGS = -Wall
LIBS = -lGL -lGLU -lglut -lGLEW

SOURCES = main.cpp\
	../GLUT/GLUT_Window.cpp\
	../core/Entity.cpp ../core/MeshObject.cpp\
	../graphics/Mesh.cpp\
	../GL/GL_RenderingSystem.cpp

ALL : $(SOURCES)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) $(PLIBS) -o $(PROGRAM)



