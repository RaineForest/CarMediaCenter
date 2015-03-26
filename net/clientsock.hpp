
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define TCP_Socket SOCK_STREAM
#define UDP_Socket SOCK_DGRAM

class ClientSocket;

class ClientSocket {
private:
	int type;
	int sock;
	struct sockaddr_in remote;
	struct hostent* server;

public:
	static ClientSocket* create(int type, const char* address, int port) {
		ClientSocket* cs = new ClientSocket();
		cs->type = type;
		cs->sock = socket(AF_INET, type, 0);
		if(cs->sock < 0) {
			return 0;
		}
		cs->server = gethostbyname(address);
		if(cs->server == 0) {
			return 0;
		}
		bzero((char*)  &cs->remote, sizeof(cs->remote));
		cs->remote.sin_family = AF_INET;
		bcopy((char*) cs->server->h_addr,
		      (char*)&cs->remote.sin_addr.s_addr,
		      cs->server->h_length);
		cs->remote.sin_port = htons(port);
		if(type == SOCK_STREAM) {
			if(connect(cs->sock, (const sockaddr*)&cs->remote, sizeof(cs->remote)) < 0) {
				return 0;
			}
		}
		return cs;
	}

	static void close(ClientSocket* cs) {
		delete cs;
	}

	int write(char* data, int len);
	int read(char* data, int len);
};
