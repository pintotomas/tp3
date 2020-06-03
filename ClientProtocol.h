#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include <string>
#include "Socket.h"
#include <vector>
namespace ClientProtocol {

    void send
    (const Socket& skt, const unsigned char *message, const std::size_t size);

    std::vector<unsigned char> receive(const Socket& skt);
}

#endif //CLIENT_PROTOCOL_H
