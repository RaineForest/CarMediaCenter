
#include <iostream>
#include "clientsock.hpp"

using namespace std;

int main(int argc, char** argv) {
	ClientSocket* cs = ClientSocket::create(TCP_Socket, "google.com", 80);
	cout << "created" << endl;
	char data[256];
	cs->read(data, 256);
	cout << "read" << endl;
	ClientSocket::close(cs);
	cout << data << endl;
	return 0;
}

