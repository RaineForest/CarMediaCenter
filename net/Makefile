
clientsock_test: clientsock.o clientsock_test.cpp
	g++ clientsock_test.cpp clientsock.o -o clientsock_test

clientsock.o: clientsock.hpp clientsock.cpp
	g++ -c clientsock.cpp -o clientsock.o

clean:
	rm *.o
