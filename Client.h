#ifndef CLIENT_H
#define CLIENT_H


#include <string>
#include "Socket.h"

class Client {
public:
    Client(char *host, char *port);

    void run();

private:
    Socket socket;

    void send_request(std::string &request);

    std::string get_response();
};


#endif //CLIENT_H
