
#include <stdio.h>
#include <unistd.h>
#include "clientsock.hpp"

int ClientSocket::write(char* data, int len) {
	if(this->type == SOCK_STREAM) {
		return ::write(this->sock, data, len);
	} else {
		//TODO: implement udp
		return -1;
	}
}

int ClientSocket::read(char* data, int len) {
	if(this->type == SOCK_STREAM) {
		return ::read(this->sock, data, len);
	} else {
		//TODO: implement udp
		return -1;
	}
}

