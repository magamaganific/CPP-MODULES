#ifndef CONVERTERS_HPP
# define CONVERTERS_HPP
# define NO 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define PINF 5
# define NINF 6
# define NAN 7
# include <string>
# include <iostream>

int		literal_is_type(std::string literal);
char	literal_to_char(std::string literal);
int		literal_to_int(std::string literal);
float	literal_to_float(std::string literal);
double	literal_to_doube(std::string literal);

#endif