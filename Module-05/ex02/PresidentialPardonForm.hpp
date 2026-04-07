#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"
# include <stdbool.h>

class Form;

class PresidentialPardonForm: public Form {
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &old);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &old);
    ~PresidentialPardonForm();

	void executeForm(Bureaucrat &target);
};


#endif