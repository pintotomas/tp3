#include <iostream>
#include "ClientListener.h"
#include "ClientHandler.h"

ClientListener::ClientListener(const char *port, std::vector<int> &numbers) : 
number_list(numbers) {
    Socket server_socket;
    server_socket.bind_and_listen(port);
    this->server_socket = std::move(server_socket);
}

ClientListener::~ClientListener() {
    join();
}

void ClientListener::stop_listening() {
    for (ClientHandler *c : clients) {
        delete c;
    }
    server_socket.close();
}
void ClientListener::run() {
    while (true) {
        Socket clientSkt;
        try {
            clientSkt = this->server_socket.accept();
        }
        catch (std::invalid_argument) {
            break;
        }
        ClientHandler *client = new ClientHandler(std::move(clientSkt),
        results, number_list.get_next());
        clients.push_back(client);
        client->start();
        garbage_collector();
    }
}

void ClientListener::print_results() {
    results();
}

void ClientListener::garbage_collector() {
    std::list<ClientHandler *>::iterator it = clients.begin();
    while (it != clients.end()) {
        if (!(*it)->is_alive()) {
            delete *it;
            it = clients.erase(it);
        } else {
            it++;
        }
    }
}
