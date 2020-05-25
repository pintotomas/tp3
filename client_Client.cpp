#include <iostream>
#include "Client.h"
#include <cstddef>
#include "Request.h"

//#include <memory.h>

Client::Client(char *host, char *port) {
    this->socket.connect(host, port);
}

bool Client::valid_request(std::string &request) {
    if (request.compare(HELP_COMMAND) == 0) {
        return true;
    } else if (request.compare(GIVEUP_COMMAND) == 0) {
        return true;
    } else if ((request.length() == NUMBER_COMMAND_LENGTH)
     && is_digits(request)) {
        return true;
    }
    return false;
}

void Client::run() {
    bool keep_playing = true;
    const std::string invalid_command_error =
     "Error: comando inválido. Escriba AYUDA para obtener ayuda";
    while (keep_playing) {
        std::string input;
        std::getline(std::cin, input);

        if (!valid_request(input)) {
            std::cout << invalid_command_error << std::endl;
            continue;
        }
        Request request(input);
        send_request(request.get_request(), request.get_size());
        unsigned char* response = get_response();
        std::string response_str(reinterpret_cast<char*>(response));
        std::cout << response_str <<std::endl;
        if ((response_str.compare("Perdiste") == 0) ||
         (response_str.compare("Ganaste") == 0)) {
            keep_playing = false;
        }
        delete[] response;
    }
}

void Client::send_request(const unsigned char* request, std::size_t size) {
    ClientProtocol::send(socket, request, size);
}

unsigned char* Client::get_response() {
    return ClientProtocol::receive(socket);
}
