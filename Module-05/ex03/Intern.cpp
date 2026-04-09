#include "Intern.hpp"

Intern::Intern(){
	std::cout<<"Intern default constructor called."<<std::endl;
}

Intern::Intern(const Intern &old){
	std::cout<<"Intern copy constructor called."<<std::endl;
	*this = old;
}

Intern &Intern::operator=(const Intern &old){
	std::cout<<"Intern assignment operator called."<<std::endl;
	if (this == &old)
		return(*this);
	return(*this);       
}

Intern::~Intern(){
	std::cout<<"Intern default destructor called."<<std::endl;
}

AForm *Intern::makeForm(std::string name, std::string target){
	static const struct{
		std::string accepted;
		int	index;

	}
	options[] = {
		{.accepted = "Shrubbery Creation", .index = 0},
		{.accepted = "Robotomy Request", .index = 1},
		{.accepted = "Presidential Pardon", .index = 2},
	};
	for (size_t i = 0; i < FORMS; i++){
		if (name == options[i].accepted){
			switch (options[i].index)
			{
			case 0:
				std::cout<<"Intern creates a Shrubbery Creation Form."<<std::endl;
				return ( new ShrubberyCreationForm(target));
			case 1:
				std::cout<<"Intern creates a Robotomy Request Form."<<std::endl;
				return ( new RobotomyRequestForm(target));
			case 2:
				std::cout<<"Intern creates a Presidential Pardon Form."<<std::endl;
				return ( new PresidentialPardonForm(target));
			default:
				break;
			}
		}
	}
	std::cout<<"Form creation failed. Intern can only make:"<<std::endl;
	std::cout<<"	Shrubbery Creation.\n	Robotomy Request.\n	Presidential Pardon."<<std::endl;
	return(NULL);
}