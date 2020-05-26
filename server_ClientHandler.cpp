#include <vector>
#include <sstream>
#include <iostream>
#include "ClientCounter.h"
#include "ClientHandler.h"

ClientHandler::ClientHandler(Socket socket, ClientCounter &client_counter,
 GameResults &game_results, const int &number) : game_results(game_results), 
 client_counter(client_counter), game(number) {
    this->peer_socket = std::move(socket);
}

ClientHandler::~ClientHandler() {
    this->peer_socket.close();
    this->join();
}

void ClientHandler::run() {
    while (!game.finished()) {
        Command *command = receive_request();
        std::string message = command->get_response(game);
        const unsigned char* response =
         reinterpret_cast<const unsigned char *>(message.c_str());
        uint16_t message_length = command->response_size;
        send_response(response, &message_length);
        delete command;
    }
    if (game.is_won()) game_results.increment_wins();
    else game_results.increment_losses();
    client_counter.remove_client();
    std::cerr << "Client disconnected!\n";
}
Command* ClientHandler::receive_request() {
    return ServerProtocol::receive(this->peer_socket);
}

void ClientHandler::send_response
(const unsigned char* response, uint16_t* size) {
    return ServerProtocol::send(this->peer_socket, response, size);
}

bool ClientHandler::is_alive() {
    return this->alive;
}
