#include "Client.h"
#include <iostream>

#define ARGC 3
#define SUCCESS 0

int main(int argc, char *argv[]) {
    if (argc != ARGC) { 
    	std::cerr << "Error: argumentos invalidos." << std::endl;
    	return SUCCESS;
    }
    char *host = argv[1];
    char *port = argv[2];
    Client client(host, port);
    client.run();
    return SUCCESS;
}
