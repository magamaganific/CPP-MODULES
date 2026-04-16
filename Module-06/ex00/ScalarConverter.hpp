#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include "converters.h"
# include <iostream>
# include <string>
# include <cstdlib>

class ScalarConverter{
protected:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &old);
	ScalarConverter &operator=(const ScalarConverter &old);
	~ScalarConverter();
public:
	static void convert(std::string literal);
};

#endif