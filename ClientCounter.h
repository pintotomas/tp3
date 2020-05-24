#ifndef CLIENT_COUNTER_H
#define CLIENT_COUNTER_H

#include <condition_variable>
#include <condition_variable>
#include <mutex>
/* Clase para saber la cantidad de clientes activos en la aplicacion
   Es un recurso compartido por el client listener y el clienthandler
*/
class ClientCounter {
 private:
  int count;
  std::mutex mutex;  
  std::condition_variable cv;

 protected:
 public:
  ClientCounter();
  ~ClientCounter();
  void add_client();
  void remove_client();
  //Espera hasta que no haya mas clientes y finalmente retorna True
  const bool wait_until_no_more_clients();
  //Elimino constructor por copia y por movimiento
  ClientCounter(const ClientCounter &) = delete;
  ClientCounter &operator=(const ClientCounter &) = delete;
};

#endif //CLIENT_COUNTER_H
