#include "Serializer.hpp"
#include <iostream>
# include <string>

int main(void)
{
	uintptr_t i = 16;
	Data *data = Serializer::deserialize(i);
	uintptr_t x = Serializer::serialize(data);

	std::cout<<"Original uintptr: "<<i<<std::endl;
	std::cout<<"Data ptr: "<<data<<std::endl;
	std::cout<<"result uintptr: "<<x<<std::endl;
	return(0);
}