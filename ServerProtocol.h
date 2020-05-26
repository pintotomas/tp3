#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <string>
#include "Socket.h"
#include "Command.h"
#include "HelpCommand.h"
#include "GiveUpCommand.h"
#include "NumberCommand.h"

namespace ServerProtocol {

    //Debe ser eliminado por el usuario
    Command* receive(const Socket& skt);
    
	void send(const Socket& skt, const unsigned char *message, const uint16_t *size);
}

#endif //SERVER_PROTOCOL_H
