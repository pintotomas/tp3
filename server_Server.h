#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include "ClientListener.h"

class Server {
public:
    Server(const char *port, std::vector<int> &numbers_file);

    void run();

private:
    ClientListener listener;
};


#endif //SERVER_H
