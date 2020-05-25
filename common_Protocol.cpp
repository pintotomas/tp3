#include "Protocol.h"
#include <iostream>

// void Protocol::send(Socket& skt, std::string &message) {
//     message += '\0';
//     for (char &c : message)
//         skt.send(reinterpret_cast<const void *>(&c), 1);
// }

// std::string Protocol::receive(Socket& skt) {
//     std::string message;
//     char c = 0;
//     while (true) {
//         skt.recv(reinterpret_cast<void *>(&c), 1);
//         if (c == '\0') break;
//         message += c;
//     }
//     return message;
// }
void Protocol::send(Socket& skt, const unsigned char *message) {

    skt.send(reinterpret_cast<const void *>(message), 1);
}

void Protocol::server_send(Socket& skt, const unsigned char *message, uint16_t *size) {
    skt.send(reinterpret_cast<const void *>(size), 2);
    skt.send(reinterpret_cast<const void *>(message), *size);
}

unsigned char* Protocol::client_receive(Socket& skt) {
    uint16_t message_size;
    skt.recv(reinterpret_cast<uint16_t*>(&message_size), 2);
	unsigned char *message = new unsigned char[message_size + 1];
	//unsigned char message_length[2];
    skt.recv(reinterpret_cast<void *>(message), message_size);
    message[message_size] = '\0';
    return message;
}

Command* Protocol::server_receive(Socket& skt) {
    //unsigned char* message = {0};
    unsigned char c = 0;
    Command * command = nullptr;
    skt.recv(reinterpret_cast<void *>(&c), 1);
    //if c == n recibir lo restante
    if (c == 'h') {
        command = new HelpCommand();
    }
    //std::cout << c <<std::endl;
    //message += c;
//    std::cout << message[0] <<std::endl;
    //return message;
    return command;
}
