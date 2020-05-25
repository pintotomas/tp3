#include "ClientProtocol.h"
#include <iostream>

void ClientProtocol::send(Socket& skt, const unsigned char *message, std::size_t size) {

    skt.send(reinterpret_cast<const void *>(message), size);
}

unsigned char* ClientProtocol::receive(Socket& skt) {
    uint16_t message_size;
    skt.recv(reinterpret_cast<uint16_t*>(&message_size), 2);
	unsigned char *message = new unsigned char[ntohs(message_size) + 1];
    skt.recv(reinterpret_cast<void *>(message), ntohs(message_size));
    message[ntohs(message_size)] = '\0';
    return message;
}
