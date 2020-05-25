#include "ServerProtocol.h"
#include <iostream>

void ServerProtocol::send
(Socket& skt, const unsigned char *message, uint16_t *size) {
    uint16_t size_converted = htons(*size);
    skt.send(reinterpret_cast<const void *>(&size_converted), 2);
    skt.send(reinterpret_cast<const void *>(message), *size);
}

Command* ServerProtocol::receive(Socket& skt) {
    unsigned char c = 0;
    Command * command = nullptr;
    skt.recv(reinterpret_cast<void *>(&c), 1);
    if (c == 'h') {
        command = new HelpCommand();
    } else if (c == 's') {
        command = new GiveUpCommand();
    } else if (c == 'n') {
        uint16_t number;
        skt.recv(reinterpret_cast<uint16_t*>(&number), 2);
        std::cout << "Received the number: " << ntohs(number) << std::endl;
        command = new NumberCommand(ntohs(number));
    }
    return command;
}
