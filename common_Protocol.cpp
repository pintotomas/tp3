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

void Protocol::server_send(Socket& skt, const unsigned char *message, uint16_t size) {
	//primero se envian 2 bytes para indicarle al cliente la longitud del msg
    skt.send(reinterpret_cast<const void *>(message), size);
}

unsigned char* Protocol::client_receive(Socket& skt) {
	unsigned char message[220] = {0};
	unsigned char* message2 = {0};
	//unsigned char message_length[2];
    skt.recv(reinterpret_cast<void *>(&message), 219);
    std::cout << message <<std::endl;
    std::cout << message2 <<std::endl;

    return message2;
}

unsigned char* Protocol::receive(Socket& skt) {
    unsigned char* message = {0};
    unsigned char c = 0;
    skt.recv(reinterpret_cast<void *>(&c), 1);
    std::cout << c <<std::endl;
    message += c;
//    std::cout << message[0] <<std::endl;
    return message;
}
