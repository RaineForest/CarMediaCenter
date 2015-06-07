
.PHONY: test default clean

default: UI.o Button.o

test:
	g++ -Wall -L/usr/lib/i386-linux-gnu -o test test.cpp -lglut -lGLU -lGL

Button.o: Button.cpp Button.hpp UI.hpp
	g++ -std=c++11 -Wall -c Button.cpp -o Button.o

UI.o: UI.hpp UI.cpp
	g++ -std=c++11 -Wall -c UI.cpp -o UI.o

clean:
	rm *.o

