#include "easyfind.hpp"
#include <list>
#include <iostream>
#include <string>

int main(void) {
	std::list<int> ints;
	std::list<int>::const_iterator it = ::easyfind(ints, 6);
	return (0);
}