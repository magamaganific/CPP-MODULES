#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac == 2){
		std::string str = av[1];
		ScalarConverter::convert(str);
	}
	else{
		std::cout<<"Invalid input. You can only introduce a literal:"<<std::endl;
		std::cout<<"	(char/int/float/double)"<<std::endl;
		std::cout<<"	 ['a'/ 1 /1.0f / 1.0]"<<std::endl;
		std::cout<<"Infinity: [inf/+inf/-inf/inff/+inff/-inff]"<<std::endl;
		std::cout<<"     Nan: [nan/nanf]"<<std::endl;
	}
	return(0);
}