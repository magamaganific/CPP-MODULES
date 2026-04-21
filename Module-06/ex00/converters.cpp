#include "ScalarConverter.hpp"
#include <limits.h>
#include <iomanip>

int	literal_is_type(std::string literal)
{
	int	sign = 1;
	int dec = 0;
	int	N = literal.length();
	int	i = -1;

	if (N == 1)
	{
		if (isdigit(literal[0]))
			return (INT);
		if (isprint(literal[0]))
			return (CHAR);
		return(NO);
	}
	if (literal == "nan" || literal == "nanf")
		return (NAN);
	if (literal == "+inf" || literal == "+inff"
		|| literal == "inff" || literal == "inf")
		return (PINF);
	if (literal == "-inf" || literal == "-inff")
		return (NINF);
	if (literal[0] == '-')
	{
		sign = -1;
		i = 0;
	}
	while (++i < N)
	{
		if (!(isdigit(literal[i]) || literal[i] == '.' || literal[i] == 'f'))
			return(NO);
		if (literal[i] == '.')
		{
			if (dec == 1)
				return (NO);
			dec = 1;
		}
		if(literal[i] == 'f')
		{
			if (i + 1 == N)
				return (FLOAT);
			return (NO);
		}
	}
	if (dec)
		return(DOUBLE);
	return(INT);
}

void	print_results(char c, long i, float f, double d)
{
	if (!isprint(c) || i > 256)
		std::cout<<"char: Non displayable"<<std::endl;
	else
		std::cout<<"char: '"<<c<<"'"<<std::endl;
	if (i > INT_MAX || i < INT_MIN)
		std::cout<<"int: impossible"<<std::endl;
	else
		std::cout<<"int: "<<i<<std::endl;
	std::cout<<std::fixed<<std::showpoint;
	std::cout<<std::setprecision(1);
	std::cout<<"float: "<<f<<"f"<<std::endl;
	std::cout<<"double: "<<d<<std::endl;
}

void	print_nan(void)
{
	std::cout<<"char: impossible"<<std::endl;
	std::cout<<"int: impossible"<<std::endl;
	std::cout<<"float: nanf"<<std::endl;
	std::cout<<"double: nan"<<std::endl;
}

void	print_pinf(void)
{
	std::cout<<"char: impossible"<<std::endl;
	std::cout<<"int: impossible"<<std::endl;
	std::cout<<"float: inf"<<std::endl;
	std::cout<<"double: inf"<<std::endl;
}

void	print_ninf(void)
{
	std::cout<<"char: impossible"<<std::endl;
	std::cout<<"int: impossible"<<std::endl;
	std::cout<<"float: -inf"<<std::endl;
	std::cout<<"double: -inf"<<std::endl;
}