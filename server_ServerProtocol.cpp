#include "ServerProtocol.h"
#include <iostream>

void ServerProtocol::send
(const Socket& skt, const unsigned char *message, const uint16_t *size) {
    uint16_t size_converted = htons(*size);
    skt.send(&size_converted, 2);
    skt.send(message, *size);
}

Command* ServerProtocol::receive(const Socket& skt) {
    unsigned char c = 0;
    Command * command = nullptr;
    skt.recv(&c, 1);
    if (c == 'h') {
        command = new HelpCommand();
    } else if (c == 's') {
        command = new GiveUpCommand();
    } else if (c == 'n') {
        uint16_t number;
        skt.recv(&number, 2);
        command = new NumberCommand(ntohs(number));
    }
    return command;
}
