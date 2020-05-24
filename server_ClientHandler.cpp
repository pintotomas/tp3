#include <vector>
#include <sstream>
#include <iostream>
#include "ClientCounter.h"
#include "ClientHandler.h"
#include "Protocol.h"

ClientHandler::ClientHandler(Socket socket, ClientCounter* client_counter, GameResults *game_results) {
    this->peer_socket = std::move(socket);
    this->client_counter = client_counter;
    this->game_results = game_results;
}

ClientHandler::~ClientHandler() {
    this->peer_socket.close();
    this->join();
}

void ClientHandler::run() {
    std::string message = "Hello World (Server)";
    send_response(message);
    while (this->alive) {
        std::string request = receive_request();
        if (request.empty()) {
            game_results->increment_wins();
            this->alive = false;
            break;
        } else { 
            std::cout << request << std::endl;
        }
        std::string response = process_request(request);
        send_response(response);
    }
    client_counter->remove_client();
    std::cerr << "Client disconnected!\n";
}

std::string ClientHandler::receive_request() {
    return Protocol::receive(this->peer_socket);
}

std::string ClientHandler::process_request(std::string &request) {
    return "Hello World (Server)";
}

void ClientHandler::send_response(std::string &basicString) {
    return Protocol::send(this->peer_socket, basicString);
}

bool ClientHandler::is_alive() {
    std::cout << "Returning: " << this->alive << std::endl;
    return this->alive;
}
