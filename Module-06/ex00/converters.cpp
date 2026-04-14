#include "converters.h"

int	string_is_type(std::string literal)
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
	if (literal == "+inf" || literal == "+inff")
		return (PINF);
	if (literal == "-inf" || literal == "-inff")
		return (NINF);
	if (literal[0] == '-')
	{
		sign = -1;
		i = 0;
	}
	while (++i <= N)
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

char	literal_to_char(std::string literal)
{
	return(literal[0]);
}

int		literal_to_int(std::string literal)
{
	int i_dec = std::stoi(literal, nullptr);
}