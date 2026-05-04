#include <iostream>
#include <string>
#include "RPN.hpp"

int main(int ac, char **av)
{{
	try
	{
		if (ac != 2)
		{
			throw ": invalid number of arguments";
		}
		RPN rpn(av[1]);
	}
	catch (std::string *error)
	{
		std::cout << "Error" << error << std::endl;
	}
}
}