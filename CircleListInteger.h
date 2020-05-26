#ifndef CIRCLELISTINTEGER_H
#define CIRCLELISTINTEGER_H

#include <vector>

class CircleListInteger {
public:
    explicit CircleListInteger(const std::vector<int> &numbers);

    const int get_next();

private:
    const std::vector<int> numbers;
    unsigned int current_position = 0;
};


#endif //CIRCLELISTINTEGER_H
