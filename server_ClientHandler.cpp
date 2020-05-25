#include <vector>
#include <sstream>
#include <iostream>
#include "ClientCounter.h"
#include "ClientHandler.h"
#include "Protocol.h"

ClientHandler::ClientHandler(Socket socket, ClientCounter &client_counter,
 GameResults &game_results, const int &number) : game_results(game_results), 
 client_counter(client_counter) {
    this->peer_socket = std::move(socket);
    std::cout << "This client has to guess the number: " << number <<std::endl;
}

ClientHandler::~ClientHandler() {
    this->peer_socket.close();
    this->join();
}

void ClientHandler::run() {
    //std::string message = "Hello World (Server)";
    //send_response(message);
    while (this->alive) {
        //std::string request = receive_request();
        unsigned char* request = receive_request();
        if (request) std::cout << "Request no nulo" << std::endl;

        //std::cout << request << std::endl;
        game_results.increment_wins();
        this->alive = false;
        //std::cout << request << std::endl
        std::string help_message = "Comandos válidos:​ \n\t​ AYUDA: despliega la lista de comandos válidos​ \n\t​ RENDIRSE: pierde el juego automáticamente​ \n\t​ XXX: Número de 3 cifras a ser enviado al servidor para adivinar el número secreto";
        const unsigned char* message = reinterpret_cast<const unsigned char *>(help_message.c_str());
        //std::cout << "ABOUT TO PRINT CASTED" << std::endl;
        //std::cout << casted << std::endl;
        uint16_t message_length = help_message.length();
        send_response(message, &message_length);
        break;
        // if (request.empty()) {
        //     game_results.increment_wins();
        //     this->alive = false;
        //     break;
        // } else { 
        //     std::cout << request << std::endl;
        // }
        // std::string response = process_request(request);
        // send_response(response);
    }
    client_counter.remove_client();
    std::cerr << "Client disconnected!\n";
}

// std::string ClientHandler::receive_request() {
//     return Protocol::receive(this->peer_socket);
// }

unsigned char* ClientHandler::receive_request() {
    return Protocol::receive(this->peer_socket);
}

// std::string ClientHandler::process_request(std::string &request) {
//     return "Hello World (Server)";
// }

void ClientHandler::send_response(const unsigned char* response, uint16_t* size) {
 //   std::cout << "PRINTING RESPONSE " << std::endl;
 //   std::cout << response << std::endl;
    return Protocol::server_send(this->peer_socket, response, size);
}

bool ClientHandler::is_alive() {
    std::cout << "Returning: " << this->alive << std::endl;
    return this->alive;
}
