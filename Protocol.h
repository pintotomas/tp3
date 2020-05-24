#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>
#include "Socket.h"

namespace Protocol {
    void send(Socket& skt, std::string &message);

    std::string receive(Socket& skt);
}

#endif //PROTOCOL_H
