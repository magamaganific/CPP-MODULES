#include "iter.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>

void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

void plusten(int &i)
{
	i = i + 10;
}

int main(void) {
	{
		char arr[] = "Dabale arroz a la Zorra el Abad";

		std::cout<<"Orginal: "<<arr<<std::endl;
		iter(arr, sizeof(arr)/sizeof(char), ft_toupper);
		std::cout<<"To upper: "<<arr<<std::endl;
		iter(arr, sizeof(arr)/sizeof(char), ft_tolower);
		std::cout<<"To lower: "<<arr<<std::endl;
	}
	{
		int arr[] = {1, 2, 3, 4 ,5};

		std::cout<<"Orginal: "<<std::endl;
		for(int i = 0; i < 5; i++)
			std::cout<<"["<<arr[i]<<"]";
		std::cout<<std::endl;
		iter(arr, 5, plusten);
		std::cout<<"Plus ten: "<<std::endl;
		for(int i = 0; i < 5; i++)
			std::cout<<"["<<arr[i]<<"]";
		std::cout<<std::endl;
	}
	{
		int arr[] = {1, 2, 3, 4 ,5};

		std::cout<<"Orginal: "<<std::endl;
		for(int i = 0; i < 5; i++)
			std::cout<<"["<<arr[i]<<"]";
		std::cout<<std::endl;
		iter(arr, 5, plusten);
		std::cout<<"Plus ten: "<<std::endl;
		for(int i = 0; i < 5; i++)
			std::cout<<"["<<arr[i]<<"]";
		std::cout<<std::endl;
	}
}