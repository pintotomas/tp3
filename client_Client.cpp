#include <iostream>
#include "Client.h"
#include <cstddef>

Client::Client(char *host, char *port) {
    this->socket.connect(host, port);
}

bool Client::valid_request(std::string &request) {
    if (request.compare(HELP_COMMAND) == 0) {
        return true;
    }
    else if (request.compare(GIVEUP_COMMAND) == 0) {
        return true;
    }
    else if ((request.length() == NUMBER_COMMAND_LENGTH) && is_digits(request)) {
        return true;
    }
    return false;
}

const unsigned char* Client::create_request(std::string input) {
    const unsigned char* request;
    if ((input.length() == NUMBER_COMMAND_LENGTH) && is_digits(input)) {
        request = reinterpret_cast<const unsigned char *>("n");
        return request;
    }
    if (input.compare(HELP_COMMAND) == 0) {
        request = reinterpret_cast<const unsigned char *>("h");
        return request;
    }
    request = reinterpret_cast<const unsigned char *>("s");
    return request;
    }

void Client::run() {

    bool keep_playing = true;
    while (keep_playing) {
        std::string input;
        std::getline(std::cin, input);
        if (!valid_request(input)) {
            std::cout << INVALID_COMMAND_ERROR << std::endl;
            continue;
        }
        const unsigned char* request = create_request(input);


        send_request(request);
        unsigned char* response = get_response();
        std::string response_str(reinterpret_cast<char*>(response));
        std::cout << response_str <<std::endl;
        if ((response_str.compare("Perdiste") == 0) || (response_str.compare("Ganaste") == 0)) {
            keep_playing = false;
        }
        delete[] response;
    }
}

// void Client::send_request(std::string &request) {
//     Protocol::send(socket, request);
// }

void Client::send_request(const unsigned char* request) {
    ClientProtocol::send(socket, request);
}

// std::string Client::get_response() {
//     return Protocol::receive(socket);
// }
unsigned char* Client::get_response() {
    return ClientProtocol::receive(socket);
}