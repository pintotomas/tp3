#ifndef SOCKET_H
#define SOCKET_H

#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>

class Socket {
    static const int FAMILY = AF_INET;
    static const int SOCK_TYPE = SOCK_STREAM;
    static const int CLIENT_FLAGS = 0;
    static const int SERVER_FLAGS = AI_PASSIVE;
    static const int MAX_CLIENTS = 15;

public:
    Socket() = default;

    ~Socket();

    explicit Socket(int i);

    void bind_and_listen(char *port);

    void connect(char *host, char *port);

    Socket accept();

    void send(const void *msg, size_t length);

    void recv(void *response, size_t length);

    void close();

    Socket(Socket &&other);

    Socket &operator=(Socket &&other);

private:
    int fd = -1;

    struct addrinfo *getAddr(const char *host, const char *service, int flags);
};

#endif //SOCKET_H
