#include <vector>
#include <iostream>
#include "server_Server.h"

Server::Server(char *port, char *numbers_file) :
    listener(port) {}

void Server::run() {
    this->listener.start();
    std::string input;
    while (input != "q") {
        std::cin >> input;
    }
    this->listener.stop_listening();
    while (!this->listener.server_is_idle()) {
    	//Espero hasta que se cierren las conexiones
    }
}
