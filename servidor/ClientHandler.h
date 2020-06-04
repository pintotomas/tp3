#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include "../red/Socket.h"
#include "../utils/Thread.h"
#include "../game/GameResults.h"
#include <string>
#include "../commands/Command.h"
#include "../protocol/ServerProtocol.h"
#include "../game/GuessNumberGame.h"

class ClientHandler : public Thread {
public:
    ClientHandler
    (Socket socket, GameResults &game_results, const int &number);
    ~ClientHandler() override;

    void run() override;

    const bool is_alive();

private:
    GameResults &game_results;

    GuessNumberGame game;

    Socket peer_socket;

    bool alive = true;

    Command* receive_request();

    void send_response(const unsigned char* response, const uint16_t *size);
};


#endif //CLIENTHANDLER_H
