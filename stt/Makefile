
.PHONY : default clean

LIBS = -lpulse-simple -lpulse

default: stt.o

stt.o: stt.cpp stt.hpp
	g++ -Wall -c stt.cpp -o stt.o

clean:
	rm *.o
