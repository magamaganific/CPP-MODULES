#include <iostream>
#include <fstream>
#include <string>

int main()
{
	// if (ac != 3)
	// 	std::cout<<"Invalid input: Introduce a .txt file"<<std::endl;
	// else
	std::fstream new_file;

	new_file.open("input.txt", std::ios::in);
	if (new_file.is_open())
	{
		std::string sa;
		while(getline(new_file, sa))
				std::cout<<sa<<"\n";
		new_file.close();
	}
}