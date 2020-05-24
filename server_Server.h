#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "ClientListener.h"

class Server {
public:
    Server(char *port, char *numbers_file);

    void run();

private:
    ClientListener listener;
};


#endif //SERVER_H
