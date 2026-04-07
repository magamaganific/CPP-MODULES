#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
# include <stdbool.h>

class AForm;

class PresidentialPardonForm: public AForm {
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &old);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &old);
    ~PresidentialPardonForm();

	void executeForm(Bureaucrat &target);
};


#endif