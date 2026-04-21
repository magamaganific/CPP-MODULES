#include "Intern.hpp"
#include <fstream>
#define B_G "\033[1;32m"
#define B_P "\033[1;35m"
#define NO "\033[m"

int main(void)
{
	try{
		std::cout<<B_G<<"Good tests:"<<NO<<std::endl;
		{
			Bureaucrat darla("Darla", 1);
			Intern mario;
			AForm *form;

			form = mario.makeForm("Shrubbery Creation", "House");
			darla.signForm(*form);
			darla.executeForm(*form);
			delete(form);
			std::cout<<std::endl;
			form = mario.makeForm("Robotomy Request", "Robot");
			darla.signForm(*form);
			darla.executeForm(*form);
			delete(form);
			std::cout<<std::endl;
			form = mario.makeForm("Presidential Pardon", "Daniel");
			darla.signForm(*form);
			darla.executeForm(*form);
			delete(form);
			std::cout<<B_P<<"\nBad tests:"<<NO<<std::endl;
			form = mario.makeForm("Invalid", "lol");
			delete(form);
		}
		std::cout<<std::endl;
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	return(0);
}