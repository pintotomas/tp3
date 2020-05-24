#include <iostream>
#include "Client.h"
#include "Protocol.h"

Client::Client(char *host, char *port) {
    this->socket.connect(host, port);
}

void Client::run() {
    std::string greeting = get_response();
    std::cout << greeting;
    while (true) {
        std::string request;
        std::getline(std::cin, request);
        if (request.empty()) break;
        send_request(request);
        std::string response = get_response();
        if (response.empty()) break;
        std::cout << response;
    }
}

void Client::send_request(std::string &request) {
    Protocol::send(this->socket, request);
}

std::string Client::get_response() {
    return Protocol::receive(this->socket);
}
