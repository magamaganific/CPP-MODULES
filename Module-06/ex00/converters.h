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
void	print_results(char c, long i, float f, double d);
void	print_nan(void);
void	print_pinf(void);
void	print_ninf(void);

#endif