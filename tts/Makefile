
.PHONY : default clean

LIBS = -lFestival -lestools -lestbase -leststring -lncurses

default: tts.o

tts_test: tts_test.cpp tts.o
	g++ -Wall -c tts_test.cpp -o tts_test.o
	g++ -Wall tts_test.o tts.o $(LIBS) -o tts_test
	
tts.o: tts.hpp tts.cpp
	g++ -Wall -c tts.cpp -o tts.o

clean:
	rm *.o
