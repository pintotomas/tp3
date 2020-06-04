#ifndef CIRCLELISTINTEGER_H
#define CIRCLELISTINTEGER_H

#include <vector>

class CircleListInteger {
public:
	//Lista circular de enteros, cada llamada a get_next 
	//devuelve el siguiente numero de la lista, de forma circular
    explicit CircleListInteger(const std::vector<int> &numbers);

    const int get_next();

private:
    const std::vector<int> numbers;
    unsigned int current_position = 0;
};


#endif //CIRCLELISTINTEGER_H
