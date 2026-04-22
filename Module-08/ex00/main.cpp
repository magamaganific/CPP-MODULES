#include "easyfind.hpp"
#include <list>
#include <iostream>
#include <string>

int main(void) {
	std::list<int> ints;
	ints.push_back(70);
	ints.push_back(10);
	ints.push_back(50);
	ints.push_back(25);
	ints.push_back(36);
	ints.push_back(67);
	ints.push_back(42);
	std::list<int>::const_iterator it = ints.end();

	try
	{
		it = easyfind(ints, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if(it != ints.end())
		std::cout<<"Found!"<<std::endl;
	it = ints.end();
	try
	{
		it = easyfind(ints, 72);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if(it != ints.end())
		std::cout<<"Found!"<<std::endl;
	it = ints.end();
	return (0);
}