#include <iostream>
#include "server_Server.h"

Server::Server(const char *port, std::vector<int> &numbers) :
    listener(port, numbers) {}

void Server::run() {
    this->listener.start();
    std::string input;
    while (input != "q") {
        std::cin >> input;
    }
    this->listener.stop_listening();
    this->listener.print_results();
}
