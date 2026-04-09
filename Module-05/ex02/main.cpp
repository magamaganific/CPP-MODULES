#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>

int main(void)
{
	try{
		{
			Bureaucrat paco("Paco", 1);
			ShrubberyCreationForm s("Home");

			paco.signForm(s);
			paco.executeForm(s);
		}
		std::cout<<std::endl;
		{
			Bureaucrat paco("Mina", 1);
			RobotomyRequestForm r("Robot");

			paco.signForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
		}
		std::cout<<std::endl;
		{
			Bureaucrat paco("Lili", 1);
			PresidentialPardonForm s("Sinner");

			paco.signForm(s);
			paco.executeForm(s);
		}
		std::cout<<std::endl;
		{
			Bureaucrat paco("Daniel", 140);
			ShrubberyCreationForm s("Shrub");

			paco.signForm(s);
			paco.executeForm(s);
		}
		std::cout<<std::endl;
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	return(0);
}