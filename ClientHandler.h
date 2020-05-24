#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include "Socket.h"
#include "Thread.h"
#include "ClientCounter.h"
#include "GameResults.h"
#include <string>

class ClientHandler : public Thread {
public:
    ClientHandler
    (Socket socket, ClientCounter* client_counter,
     GameResults &game_results, const int &number);

    ~ClientHandler() override;

    void run() override;

    bool is_alive();

private:
    GameResults &game_results;

    Socket peer_socket;

    ClientCounter* client_counter;

    bool alive = true;

    std::string receive_request();

    std::string process_request(std::string &request);

    void send_response(std::string &response_string);
};


#endif //CLIENTHANDLER_H
