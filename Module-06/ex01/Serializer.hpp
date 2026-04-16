#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "Data.h"
# include <iostream>
# include <stdint.h>
# include <string>
# include <cstdlib>

class Serializer{
protected:
	Serializer();
	Serializer(const Serializer &old);
	Serializer &operator=(const Serializer &old);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif