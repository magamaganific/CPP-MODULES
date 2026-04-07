#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include <stdbool.h>

class Form;

class ShrubberyCreationForm: public Form{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &old);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &old);
    ~ShrubberyCreationForm();

	void executeForm(Bureaucrat &target);
};


#endif