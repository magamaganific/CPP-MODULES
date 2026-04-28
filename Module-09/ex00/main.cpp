#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <map>

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout<<"Invalid input: Introduce a .txt file"<<std::endl;
	else
	{
		std::string input = av[1];
		if (input.substr(input.size() - 4) != ".txt")
			std::cout<<"Invalid input: Introduce a .txt file"<<std::endl;
		try
		{
			DatesValues txt(input);
			DatesValues dta("data.csv");
		}
		catch(std::exception &e){
			std::cout<<e.what()<<std::endl;
		}  
	}
	// (void) ac;
	// (void) av;
	// std::map<std::string, float> m1;
	// std::string hi = "hi";
	// float f = 10.0;
	// m1.insert(std::make_pair(hi, f));
	// std::map<std::string, float>::iterator it = m1.lower_bound("hi");
	// std::cout<<it->first<<std::endl;
	// std::cout<<it->second<<std::endl;

    // std::string cadena = "Hola Mundo, bienvenido a C++";
    // int inicio_resto = 12; // Posición después de la subcadena deseada
    
    // // Obtiene desde la posición 12 hasta el final
    // std::string resto = cadena.substr(inicio_resto);
    
    // std::cout << "Resto: " << resto << std::endl; // Salida: ", bienvenido a C++"
    // std::string re = cadena.substr(0, 4);
    // std::cout << "Re: " << re << std::endl; // Salida: ", bienvenido a C++"
    return 0;
    return (0);
}