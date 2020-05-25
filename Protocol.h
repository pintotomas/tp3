#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>
#include "Socket.h"

namespace Protocol {
    //void send(Socket& skt, std::string &message);

   // std::string receive(Socket& skt);
    void send(Socket& skt, const unsigned char *message);

    unsigned char* client_receive(Socket& skt);

    unsigned char* receive(Socket& skt);
    
	void server_send(Socket& skt, const unsigned char *message, uint16_t *size);
}

#endif //PROTOCOL_H
