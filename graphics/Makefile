CC = g++
OUT = sr_graphics.a
FLAGS = -Wall -c
SOURCES = *.cpp
OBJ = $(SOURCES:.cpp=o)
LIBS = ../math/sr_math.a

$(OUT) : $(OBJ)
	ar rcs $(OUT) $(OBJ) $(LIBS)

$(OBJ) : $(SOURCES)
	$(CC) $(FLAGS) $(SOURCES) 
	
