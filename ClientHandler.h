#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include "Socket.h"
#include "Thread.h"
#include "GameResults.h"
#include <string>
#include "Command.h"
#include "ServerProtocol.h"
#include "GuessNumberGame.h"

class ClientHandler : public Thread {
public:
    //Instancia un nuevo manejador de clientes para que juege 
    //a un juego de GuessNumberGame utilizando el numero 'number'
    ClientHandler
        (Socket socket, GameResults &game_results, const int &number);
    ~ClientHandler() override;
    /*
    Corre hasta que termine el juego, el juego terminara cuando:
    - El cliente adivina el numero
    - El cliente avise que se rinda
    - El cliente termina su decimo intento sin adivinar el numero.
    */
    void run() override;
    // Devuelve True mientras el juego siga en curso
    const bool is_alive();

private:
    GameResults &game_results;

    GuessNumberGame game;

    Socket peer_socket;

    bool alive = true;
    /* Recibe un nuevo comando del cliente
     (AYUDA, RENDIRSE, o un numero de 3 cifras)*/
    Command* receive_request();
    /*Envia una respuesta al comando recibido, segun como afecte el comando
    al juego*/
    void send_response(const unsigned char* response, const uint16_t *size);
};


#endif //CLIENTHANDLER_H
