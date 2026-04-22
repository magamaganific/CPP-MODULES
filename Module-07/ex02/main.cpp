#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include "Array.hpp"
#define MAX_VAL 750

int main(void) {
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	{
		std::cout<<"Co-creation test:"<<std::endl;
		Array<int> nums(100);
		int *nbrs = new int[100];

		srand(time(NULL));
		for (int i = 0; i < 100; i++)
		{
			int val = rand() % 100;
			nums[i] = val;
			nbrs[i] = val;
		}
		std::cout<<"	nums[10]-> "<<nums[10]<<std::endl;
		std::cout<<"	nbrs[10]-> "<<nbrs[10]<<std::endl;
		std::cout<<"	nums[99]-> "<<nums[99]<<std::endl;
		std::cout<<"	nbrs[99]-> "<<nbrs[99]<<std::endl;
		std::cout<<"	nums[0]-> "<<nums[0]<<std::endl;
		std::cout<<"	nbrs[0]-> "<<nbrs[0]<<std::endl;
	}
	std::cout<<"\n"<<std::endl;
	{
		std::cout<<"Copy test:"<<std::endl;
		Array<int> nums(100);

		srand(time(NULL));
		for (int i = 0; i < 100; i++)
		{
			int val = rand() % 100;
			nums[i] = val;
		}
		Array<int> nbrs(nums);
		std::cout<<"	nums[10]-> "<<nums[10]<<std::endl;
		std::cout<<"	nbrs[10]-> "<<nbrs[10]<<std::endl;
		std::cout<<"	nums[99]-> "<<nums[99]<<std::endl;
		std::cout<<"	nbrs[99]-> "<<nbrs[99]<<std::endl;
		std::cout<<"	nums[0]-> "<<nums[0]<<std::endl;
		std::cout<<"	nbrs[0]-> "<<nbrs[0]<<std::endl;
	}
	std::cout<<"\n"<<std::endl;
	std::cout<<"Error Tests"<<std::endl;
	try{
		Array<int> nums(100);

		srand(time(NULL));
		for (int i = 0; i < 100; i++)
		{
			int val = rand() % 100;
			nums[i] = val;
		}
		std::cout<<"	nums[100]-> "<<nums[100]<<std::endl;

	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
}