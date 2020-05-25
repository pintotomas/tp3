#ifndef CLIENT_H
#define CLIENT_H

#include "helper_functions.h"
#include <string>
#include "Socket.h"
#include "ClientProtocol.h"

#define HELP_COMMAND "AYUDA"
#define GIVEUP_COMMAND "RENDIRSE"
#define NUMBER_COMMAND_LENGTH 3
#define INVALID_COMMAND_ERROR "Error: comando inválido. Escriba AYUDA para obtener ayuda"

class Client {
public:
    Client(char *host, char *port);

    void run();

private:
    Socket socket;

    bool valid_request(std::string &request);

    //void send_request(std::string &request);

    void send_request(const unsigned char* request);

	unsigned char* get_response();

    //std::string get_response();
	unsigned char* create_request(std::string input);
};


#endif //CLIENT_H
