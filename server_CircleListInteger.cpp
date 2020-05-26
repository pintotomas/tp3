#include "CircleListInteger.h"

CircleListInteger::CircleListInteger
(const std::vector<int> &numbers) : numbers(numbers) {}

const int CircleListInteger::get_next() {
	int current_number = numbers.at(current_position);
	current_position ++;
	if (current_position == numbers.size()) current_position = 0;
	return current_number;
}
