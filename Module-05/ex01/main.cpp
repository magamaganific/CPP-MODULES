#include "Bureaucrat.hpp"
#define B_G "\033[1;32m"
#define B_P "\033[1;35m"
#define NO "\033[m"

int main(void)
{
	try{
		std::cout<<B_G<<"Good tests:"<<NO<<std::endl;
		{
			Bureaucrat lisa("Lisa", 1);
			Form democracy("Democracy", 2, 3);

			lisa.decrement();
			lisa.signForm(democracy);
			std::cout<<lisa;
		}
		std::cout<<std::endl;
		{
			Bureaucrat lisa("Lisa", 104);
			Form democracy("Democracy", 140, 100);

			lisa.decrement();
			lisa.decrement();
			lisa.decrement();
			lisa.signForm(democracy);
			std::cout<<lisa;
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<B_P<<"\nBad tests:"<<NO<<std::endl;
	try{
		{
			Bureaucrat lisa("Lisa", 10);
			Form democracy("Democracy", 2, 3);

			lisa.signForm(democracy);
			std::cout<<lisa;
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	try{
		{
			Bureaucrat lisa("Lisa", 10);
			Form democracy("Democracy", 200, 3);

			lisa.signForm(democracy);
			std::cout<<lisa;
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	try{
		{
			Bureaucrat lisa("Lisa", 10);
			Form democracy("Democracy", 2, 300);

			lisa.signForm(democracy);
			std::cout<<lisa;
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	try{
		{
			Bureaucrat lisa("Lisa", 10);
			Form democracy("Democracy", -2, 3);

			lisa.signForm(democracy);
			std::cout<<lisa;
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	try{
		{
			Bureaucrat lisa("Lisa", 10);
			Form democracy("Democracy", 2, -3);

			lisa.signForm(democracy);
			std::cout<<lisa;
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	return(0);
}