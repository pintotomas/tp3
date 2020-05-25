#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include <string>
#include "Socket.h"

namespace ClientProtocol {

    void send(Socket& skt, const unsigned char *message);

    unsigned char* receive(Socket& skt);
}

#endif //CLIENT_PROTOCOL_H
