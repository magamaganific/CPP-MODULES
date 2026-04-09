#include "Intern.hpp"

#include <fstream>

int main(void)
{
	try{
		{
			Bureaucrat darla("Darla", 1);
			Intern mario;
			AForm *form;

			form = mario.makeForm("Shrubbery Creation", "House");
			darla.signForm(*form);
			darla.executeForm(*form);
			delete(form);
			form = mario.makeForm("Robotomy Request", "Robot");
			delete(form);
			form = mario.makeForm("Presidential Pardon", "Daniel");
			delete(form);
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