#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>
#include "Socket.h"
#include "Command.h"
#include "HelpCommand.h"
#include "GiveUpCommand.h"

namespace Protocol {
    //void send(Socket& skt, std::string &message);

   // std::string receive(Socket& skt);
    void send(Socket& skt, const unsigned char *message);

    unsigned char* client_receive(Socket& skt);
    //Debe ser eliminado por el usuario
    Command* server_receive(Socket& skt);
    
	void server_send(Socket& skt, const unsigned char *message, uint16_t *size);
}

#endif //PROTOCOL_H
