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
        //unsigned char* request = receive_request();
        //if (request) std::cout << "Request no nulo" << std::endl;
        Command *command = receive_request();
        //std::cout << command->get_response() << std::endl;
        //std::cout << "Response size:" <<command->response_size << std::endl;

        //std::cout << request << std::endl;


        std::string message = command->get_response();
        //if momentaneoi para cortar la ejecucion
        if ((message.compare("Perdiste") == 0)) {
            this->alive = false;
        }
                
        const unsigned char* response = reinterpret_cast<const unsigned char *>(message.c_str());
        //std::cout << "ABOUT TO PRINT CASTED" << std::endl;
        //std::cout << casted << std::endl;
        uint16_t message_length = command->response_size;
        send_response(response, &message_length);
        delete command;
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
    game_results.increment_losses();
    client_counter.remove_client();
    std::cerr << "Client disconnected!\n";
}

// std::string ClientHandler::receive_request() {
//     return Protocol::receive(this->peer_socket);
// }

//unsigned char* ClientHandler::receive_request() {
Command* ClientHandler::receive_request() {
    return Protocol::server_receive(this->peer_socket);
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
