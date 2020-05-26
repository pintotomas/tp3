#include <iostream>
#include "Client.h"
#include <cstddef>
#include "Request.h"
//#include <memory.h>

Client::Client(const char *host, const char *port) {
    this->socket.connect(host, port);
}

const bool Client::valid_request(std::string &request) {
    const std::string invalid_command_error =
     "Error: comando inválido. Escriba AYUDA para obtener ayuda";
    const std::string invalid_number_error = 
    "Número inválido. Debe ser de 3 cifras no repetidas";
    if (request.compare(HELP_COMMAND) == 0) {
        return true;
    } else if (request.compare(GIVEUP_COMMAND) == 0) {
        return true;
    } else if (is_digits(request)) {
        if (str_to_uint16(request.c_str())) { return true;
        } else {
            std::cout << invalid_command_error << std::endl;
            return false;
        }
    }
    std::cout << invalid_command_error << std::endl;
    return false;
}

void Client::run() {
    bool keep_playing = true;

    while (keep_playing) {
        std::string input;
        std::getline(std::cin, input);

        if (!valid_request(input)) {
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
