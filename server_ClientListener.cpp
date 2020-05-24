#include <iostream>
#include "ClientListener.h"
#include "ClientHandler.h"

ClientListener::ClientListener(char *port, std::vector<int> &numbers) : 
number_list(numbers) {
    Socket server_socket;
    server_socket.bind_and_listen(port);
    //client_counter = new ClientCounter();
    this->server_socket = std::move(server_socket);
}

ClientListener::~ClientListener() {
    for (ClientHandler *c : clients) {
        delete c;
    }
    //delete client_counter;
    //delete results;
    join();
}

void ClientListener::stop_listening() {
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
        std::cerr << "New Client!\n";
        ClientHandler *client = new ClientHandler(std::move(clientSkt),
         client_counter, results, number_list.get_next());
        clients.push_back(client);
        client->start();
        client_counter.add_client();
        garbage_collector();
    }
}

bool ClientListener::server_is_idle() {
    return client_counter.wait_until_no_more_clients();
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
