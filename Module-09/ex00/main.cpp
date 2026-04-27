#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <map>

int main()
{
	if (ac != 2)
		std::cout<<"Invalid input: Introduce a .txt file"<<std::endl;
	else
	{
		std::string input = av[1];
		if (input.substr(input.size() - 4) != ".txt")
			std::cout<<"Invalid input: Introduce a .txt file"<<std::endl;
	}
	// std::map<std::string, float> m1;
	// std::string hi = "hi";
	// float f = 10.0;
	// m1.insert(std::make_pair(hi, f));
	// std::map<std::string, float>::iterator it = m1.lower_bound("hi");
	// std::cout<<it->first<<std::endl;
	// std::cout<<it->second<<std::endl;
    return (0);
}