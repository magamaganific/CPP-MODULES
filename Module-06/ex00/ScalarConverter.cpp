#include "ScalarConverter.hpp"
#include <cstdlib>

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
	int		type = literal_is_type(literal);
	char	c = 0;
	long	i = 0;
	float	f = 0.0f;
	double	d = 0.0;

	if (!type)
	{
		std::cout<<"Invalid input. You can only introduce a literal:"<<std::endl;
		std::cout<<"	(char/int/float/double)"<<std::endl;
		std::cout<<"	 ['a'/ 1 /1.0f / 1.0]"<<std::endl;
		std::cout<<"Infinity: [inf/+inf/-inf/inff/+inff/-inff]"<<std::endl;
		std::cout<<"     Nan: [nan/nanf]"<<std::endl;
		return ;
	}
	if (type == CHAR)
	{
		c = literal[0];
		i = c; f = i; d = i;
	}
	else if (type == INT)
	{
		i = atol(literal.c_str());
		c = i; f += i; d += i;
	}
	else if (type == FLOAT)
	{
		f += atof(literal.c_str());
		d += f; i = f; c = i;
	}
	else if (type == DOUBLE)
	{
		d += atof(literal.c_str());
		f += d; i = d; c = i;
	}
	else if (type == NAN)
		return(print_nan());
	else if (type == PINF)
		return(print_pinf());
	else if (type == NINF)
		return(print_ninf());
	print_results(c, i, f, d);
}