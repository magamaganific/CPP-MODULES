#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout<<"Invalid input: Introduce a .txt file"<<std::endl;
	else
	{
		std::string input = av[1];
		if (input.substr(input.size() - 4) != ".txt")
			std::cout<<"Invalid input: Introduce a .txt file"<<std::endl;
	}
}