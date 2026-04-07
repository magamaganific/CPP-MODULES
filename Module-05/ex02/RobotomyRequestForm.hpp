#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"
# include <stdbool.h>

class Form;

class RobotomyRequestForm{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(int sign_grade, int exec_grade);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &old);
    ~RobotomyRequestForm();

	void executeForm(Bureaucrat &target);
};


#endif