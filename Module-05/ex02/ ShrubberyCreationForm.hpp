#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <stdbool.h>

class Form;

class ShrubberyCreationForm: public AForm{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &old);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &old);
    ~ShrubberyCreationForm();

	const std::string &getTarget()const;
	void executeForm(Bureaucrat &target);
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &s); 
#endif