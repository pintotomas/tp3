#include "ClientProtocol.h"
#include <iostream>

void ClientProtocol::send
(const Socket& skt, const unsigned char *message, const std::size_t size) {
    skt.send(reinterpret_cast<const void *>(message), size);
}

std::vector<unsigned char> ClientProtocol::receive(const Socket& skt) {
    uint16_t message_size;
    skt.recv(reinterpret_cast<uint16_t*>(&message_size), 2);
    std::vector<unsigned char> message(ntohs(message_size) + 1);
    skt.recv(reinterpret_cast<void *>(&message[0]), ntohs(message_size));
    message[ntohs(message_size)] = '\0';
    return message;
}
