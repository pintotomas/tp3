#ifndef CLIENT_H
#define CLIENT_H

#include "helper_functions.h"
#include <string>
#include "Socket.h"
#include "ClientProtocol.h"

class Client {
public:
    Client(const char *host, const char *port);

    void run();

private:
    Socket socket;

    const bool valid_request(std::string &request);

    void send_request(const unsigned char* request, std::size_t size);

	unsigned char* get_response();
};


#endif //CLIENT_H
