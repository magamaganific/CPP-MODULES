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
			std::cout<<std::endl;
		}
		// {
		// 	Bureaucrat lisa("Lisa", 1);
		// 	AForm democracy("Democracy", 2, 3);

		// 	lisa.decrement();
		// 	lisa.signForm(democracy);
		// 	std::cout<<lisa;
		// }
		// {
		// 	Bureaucrat mario("Mario", 150);
		// 	mario.increment();
		// 	std::cout<<mario;
		// }
		// {
		// 	Bureaucrat lisa("Lisa", 1);
		// 	lisa.increment();
		// }
		// {
		// 	Bureaucrat mario("Mario", 150);
		// 	mario.decrement();
		// }
		// {
		// 	Bureaucrat hector("Hector", -1);
		// }
		// {
		// 	Bureaucrat luis("Luis", 151);
		// }
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	return(0);
}