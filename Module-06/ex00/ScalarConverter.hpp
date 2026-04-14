#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include "converters.h"
# include <iostream>

class ScalarConverter{
public:
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &old) = delete;
	ScalarConverter &operator=(const ScalarConverter &old);
	~ScalarConverter();

	static void convert(std::string literal);
};

#endif