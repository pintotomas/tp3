#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include "Socket.h"
#include "Thread.h"
#include "ClientCounter.h"
#include "GameResults.h"
#include <string>
#include "Command.h"
#include "ServerProtocol.h"
#include "GuessNumberGame.h"


class ClientHandler : public Thread {
public:
    ClientHandler
    (Socket socket, ClientCounter &client_counter,
     GameResults &game_results, const int &number);

    ~ClientHandler() override;

    void run() override;

    bool is_alive();

private:
    GameResults &game_results;

    ClientCounter &client_counter;

    GuessNumberGame game;

    Socket peer_socket;

    bool alive = true;

    //std::string receive_request();
    Command* receive_request();
    //std::string process_request(std::string &request);

    void send_response(const unsigned char* response, uint16_t *size);
};


#endif //CLIENTHANDLER_H
