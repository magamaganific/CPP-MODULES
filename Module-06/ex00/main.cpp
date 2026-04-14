#include <iostream>
# include <string>

int main(int ac, char **av)
{
	std::cout<<"✽"<<std::endl;
	std::string str = "1234.6";
	int i_dec = std::stoi(str, nullptr);
	std::cout<<i_dec<<std::endl;
	return(0);
}