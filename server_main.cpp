#include "server_Server.h"

int main(int argc, char *argv[]) {
    if (argc != 3) return 1;
    char *port = argv[1];
    char *numbers_file = argv[2];
    Server server(port, numbers_file);
    server.run();
    return 0;
}
