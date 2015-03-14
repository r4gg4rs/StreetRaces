CC = g++
PROGRAM = run
FLAGS = -Wall
LIBS = -lGL -lGLU -lglut -lGLEW

SOURCES = main.cpp\
	../GLUT/GLUT_Window.cpp\
	../core/CoreEngine.cpp ../core/ObjectFactory.cpp ../core/Scene.cpp ../core/MeshObject.cpp ../core/Entity.cpp\
	../graphics/Mesh.cpp\
	../GL/GL_ArrayBuffer.cpp ../GL/GL_ElementBuffer.cpp ../GL/GL_VAO.cpp\
	../GL/GL_Renderer.cpp ../GL/Shader.cpp\
	../camera/Camera.cpp

ALL : $(SOURCES)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) $(PLIBS) -o $(PROGRAM)



