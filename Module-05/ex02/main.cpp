#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <fstream>

int main(void)
{
	try{
		{
			Bureaucrat paco("Paco", 1);
			ShrubberyCreationForm s("Shrub");

			paco.signForm(s);
			paco.executeForm(s);
			std::cout<<std::endl;
		}
		{
			Bureaucrat paco("Mina", 1);
			RobotomyRequestForm r("Shrub");

			paco.signForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			paco.executeForm(r);
			std::cout<<std::endl;
		}
		{
			Bureaucrat paco("Paco", 140);
			ShrubberyCreationForm s("Shrub");

			paco.signForm(s);
			paco.executeForm(s);
			std::cout<<std::endl;
		}
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	return(0);
}