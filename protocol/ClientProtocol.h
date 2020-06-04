#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include <string>
#include "../red/Socket.h"
#include <vector>
namespace ClientProtocol {

    void send_request
    (const Socket& skt, const unsigned char *message, const std::size_t size);

    std::vector<unsigned char> receive_request_response(const Socket& skt);
}

#endif //CLIENT_PROTOCOL_H
