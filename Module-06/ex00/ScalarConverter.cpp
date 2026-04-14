#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	std::cout << "Default [ScalarConverter] constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &old){
	std::cout << "[ScalarConverter] copy constructor called" << std::endl;
	*this = old;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &old){
	std::cout << "[ScalarConverter] assignment operator called" << std::endl;
	if (this == &old)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter(){
	std::cout << "[ScalarConverter] destructor called" << std::endl;
}

void ScalarConverter::convert(std::string literal){
	char	c;
	int		i;
	float	f;
	double	d;
	int		isdec;
}