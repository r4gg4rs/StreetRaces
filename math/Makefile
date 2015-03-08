sr_math.a : math.o vec_alg.o
	g++ -shared -o sr_math.so math.o vec_alg.o	
	
math.o : math.cpp
	g++ -c -Wall -Werror -dPIC math.cpp
	
vec_alg.o : vec_alg.cpp
	g++ -c -Wall -Werror -fPIC vec_alg.cpp
