#include "ClientProtocol.h"
#include <iostream>

void ClientProtocol::send(Socket& skt, const unsigned char *message, std::size_t size) {

    skt.send(reinterpret_cast<const void *>(message), size);
}

unsigned char* ClientProtocol::receive(Socket& skt) {
    uint16_t message_size;
    skt.recv(reinterpret_cast<uint16_t*>(&message_size), 2);
    uint16_t correct_message_size = ntohs(message_size);
	//unsigned char *message = new unsigned char[message_size + 1];
	unsigned char *message = new unsigned char[correct_message_size + 1];
	//unsigned char message_length[2];
    skt.recv(reinterpret_cast<void *>(message), correct_message_size);
    message[correct_message_size] = '\0';
    return message;
}
