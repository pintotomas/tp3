#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <string>
#include "Socket.h"
#include "Command.h"
#include "HelpCommand.h"
#include "GiveUpCommand.h"
#include "NumberCommand.h"

namespace ServerProtocol {
	/*Recibe un request del cliente y lo interpreta creando un Comando
    POST: El comando devuelto debe ser eliminado por el usuario*/
    Command* receive_command(const Socket& skt);
    /*Envia respuesta a el comando recibido*/
	void send_response_to_command
	(const Socket& skt, const unsigned char *message, const uint16_t *size);
}

#endif //SERVER_PROTOCOL_H
