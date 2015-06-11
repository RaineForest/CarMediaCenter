
.PHONY: test default clean

default: Button.o Event.o UIFrame.o UIHierarchy.o UIUtil.o

test:
	g++ -std=c++11 -Wall -L/usr/lib/i386-linux-gnu -o test test.cpp -lglut -lGLU -lGL -lm

Button.o: Button.cpp Button.hpp UIHierarchy.hpp UIUtil.hpp
	g++ -std=c++11 -Wall -c Button.cpp -o Button.o

Event.o: Event.cpp Event.hpp
	g++ -std=c++11 -Wall -c Event.cpp -o Event.o

UIFrame.o: UIFrame.cpp UIFrame.hpp UIHierarchy.hpp
	g++ -std=c++11 -Wall -c UIFrame.cpp -o UIFrame.o

UIHierarchy.o: UIHierarchy.cpp UIHierarchy.hpp UIUtil.hpp Event.hpp
	g++ -std=c++11 -Wall -c UIHierarchy.cpp -o UIHierarchy.o

UIUtil.o: UIUtil.cpp UIUtil.hpp
	g++ -std=c++11 -Wall -c UIUtil.cpp -o UIUtil.o

clean:
	-rm *.o

