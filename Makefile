
INCLUDES = -I./festival/src/include -I./speech_tools/include
LIBDIRS = -L./festival/src/lib -L./speech_tools/lib
LIBS = -lFestival -lestools -lestbase -leststring -lncurses

default:
	echo "no default target implemented yet"

tts_test: tts_test.cpp tts.o
	g++ $(INCLUDES) -c tts_test.cpp -o tts_test.o
	g++ $(LIBDIRS) tts_test.o tts.o $(LIBS) -o tts_test
	
tts.o: tts.hpp tts.cpp
	g++ $(INCLUDES) -c tts.cpp -o tts.o

clean:
	rm *.o
