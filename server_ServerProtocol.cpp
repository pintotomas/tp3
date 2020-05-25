#include "ServerProtocol.h"
#include <iostream>

void ServerProtocol::send(Socket& skt, const unsigned char *message, uint16_t *size) {
    skt.send(reinterpret_cast<const void *>(size), 2);
    skt.send(reinterpret_cast<const void *>(message), *size);
}

Command* ServerProtocol::receive(Socket& skt) {
    //unsigned char* message = {0};
    unsigned char c = 0;
    Command * command = nullptr;
    skt.recv(reinterpret_cast<void *>(&c), 1);
    //if c == n recibir lo restante
    if (c == 'h') {
        command = new HelpCommand();
    }
    else if (c == 's') {
        command = new GiveUpCommand();
    }
    else if (c == 'n') {
        std::cout << "RECEIVED A NUMBER!!" <<std::endl;
        uint16_t number;
        std::cout << "THE NUMBER IS" << number <<std::endl;
        skt.recv(reinterpret_cast<uint16_t*>(&number), 2);
        command = new NumberCommand(number);
    }
    return command;
}
