#ifndef CLIENTLISTENER_H
#define CLIENTLISTENER_H

#include "Socket.h"
#include "Thread.h"
#include "ClientHandler.h"
#include <list>


class ClientListener : public Thread {
public:
    explicit ClientListener(char *port);

    ~ClientListener() override;

    void run() override;

    // Devuelve True si cuando el server se encuentre sin
    // Atender a mas clientes
    bool server_is_idle();
    void stop_listening();

private:
    Socket server_socket;
    std::list<ClientHandler *> clients;
    ClientCounter* client_counter;
    void garbage_collector();
};

#endif //CLIENTLISTENER_H
