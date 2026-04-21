#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>
#define B_G "\033[1;32m"
#define B_P "\033[1;35m"
#define NO "\033[m"

int main(void)
{
	try{
		std::cout<<B_G<<"Good tests:"<<NO<<std::endl;
		{
			Bureaucrat paco("Paco", 1);
			Bureaucrat mina("Mina", 1);
			ShrubberyCreationForm s("Home");

			paco.signForm(s);
			mina.executeForm(s);
		}
		std::cout<<std::endl;
		{
			Bureaucrat mina("Mina", 1);
			Bureaucrat paco("Paco", 1);
			RobotomyRequestForm r("Robot");

			mina.signForm(r);
			paco.executeForm(r);
			mina.executeForm(r);
			mina.executeForm(r);
			mina.executeForm(r);
			mina.executeForm(r);
			mina.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
		}
		std::cout<<std::endl;
		{
			Bureaucrat lili("Lili", 1);
			PresidentialPardonForm s("Sinner");

			lili.signForm(s);
			lili.executeForm(s);
		}
		std::cout<<std::endl;
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<B_P<<"\nBad tests:"<<NO<<std::endl;
	try{
		{
			Bureaucrat daniel("Daniel", 140);
			ShrubberyCreationForm s("Shrub");

			daniel.signForm(s);
			daniel.executeForm(s);
		}
		std::cout<<std::endl;
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	try{
		{
			Bureaucrat paco("Paco", 1);
			Bureaucrat mina("Mina", 150);
			RobotomyRequestForm s("Home");

			paco.signForm(s);
			mina.executeForm(s);
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	std::cout<<std::endl;
	try{
		{
			Bureaucrat paco("Paco", 1);
			Bureaucrat mina("Mina", 150);
			PresidentialPardonForm s("Paco");

			paco.signForm(s);
			mina.executeForm(s);
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	return(0);
}