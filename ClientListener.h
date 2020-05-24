#ifndef CLIENTLISTENER_H
#define CLIENTLISTENER_H

#include "Socket.h"
#include "Thread.h"
#include "ClientHandler.h"
#include <list>
#include "GameResults.h"
#include "CircleListInteger.h"
#include <vector>

class ClientListener : public Thread {
public:
    ClientListener(char *port, std::vector<int> &numbers);

    ~ClientListener() override;

    void run() override;

    // Devuelve True si cuando el server se encuentre sin
    // Atender a mas clientes
    bool server_is_idle();
    void stop_listening();
    void print_results();

private:
    CircleListInteger number_list;
    GameResults *results;
    Socket server_socket;
    std::list<ClientHandler *> clients;
    ClientCounter* client_counter;
    void garbage_collector();
};

#endif //CLIENTLISTENER_H
