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
    ClientListener(const char *port, std::vector<int> &numbers);

    ~ClientListener() override;

    void run() override;
    void stop_listening();
    //Muestra los resultados de los juegos
    void print_results();

private:
    CircleListInteger number_list;
    GameResults results;
    Socket server_socket;
    std::list<ClientHandler *> clients;
    void garbage_collector();
};

#endif //CLIENTLISTENER_H
