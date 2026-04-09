#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# define FORMS 3

class Intern{
public:
	Intern();
	Intern(const std::string &name, int grade);
	Intern(const Intern &old);
	Intern &operator=(const Intern &old);
	~Intern();

	AForm *makeForm(std::string name, std::string target);
};

#endif