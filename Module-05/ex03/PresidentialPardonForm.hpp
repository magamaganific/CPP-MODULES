#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
# include <stdbool.h>

class AForm;

class PresidentialPardonForm: public AForm{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &old);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &old);
    ~PresidentialPardonForm();

	const std::string &getTarget()const;
	void execute(Bureaucrat const &exec)const;
private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &s); 


#endif