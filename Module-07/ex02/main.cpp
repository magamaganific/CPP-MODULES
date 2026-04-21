#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include "Array.hpp"

int main(void) {
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
}