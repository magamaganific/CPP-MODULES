#include "Bureaucrat.hpp"
#define B_G "\033[1;32m"
#define B_P "\033[1;35m"
#define NO "\033[m"

int main(void)
{
	try{
		std::cout<<B_G<<"Good tests:"<<NO<<std::endl;
		{
			Bureaucrat lisa;
			lisa.decrement();
			std::cout<<lisa;
		}
		std::cout<<std::endl;
		{
			Bureaucrat mario("Mario", 150);
			mario.increment();
			std::cout<<mario;
		}
		std::cout<<std::endl;
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<B_P<<"\nBad tests:"<<NO<<std::endl;
	try{
		{
			Bureaucrat lisa("Lisa", 1);
			lisa.increment();
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	try{
		{
			Bureaucrat mario("Mario", 150);
			mario.decrement();
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	try{
		{
			Bureaucrat hector("Hector", -1);
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	try{
		{
			Bureaucrat luis("Luis", 151);
		}

	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	return(0);
}