#ifndef CLIENT_H
#define CLIENT_H

#include "helper_functions.h"
#include <string>
#include "Socket.h"
#include "ClientProtocol.h"
#include <vector>
class Client {
public:
    Client(const char *host, const char *port);

    void run();

private:
    Socket socket;
    /*Devuelve True si el usuario esta intentando pedir ayuda,
    rendirse o enviar un numero al servidor.
    Si no, devuelve False ya que no es un comando soportado.*/
    const bool valid_request(std::string &request);
    /* PRE: fue validado anteriormente el request que el usuario intenta
    enviar al servidor. 
    Envia un request al servidor.Debe ser un caracter seguido (o no) de un
    uint_16t (solo si el primer caracter es un n) casteado a unsigned char*
    size es 1 + sizeof(uint_t) si corresponde.
     */  
    void send_request(const unsigned char* request, std::size_t size);
    /*
    Recibe la respuesta al request enviado usando send_request, 
    es una cadena de caracteres casteada a unsigned char*
    */
	std::vector<unsigned char> get_response();
};

#endif //CLIENT_H
