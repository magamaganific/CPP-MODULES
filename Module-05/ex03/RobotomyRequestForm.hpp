#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <stdbool.h>

class AForm;

class RobotomyRequestForm: public AForm{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &old);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &old);
    ~RobotomyRequestForm();

	const std::string &getTarget()const;
	void execute(Bureaucrat const &exec)const;
private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &s); 

#endif