#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Bureaucrat.hpp"
#include <stdbool.h>

class Bureaucrat;

class RobotomyRequestForm{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &old);
    RobotomyRequestForm(int sign_grade, int exec_grade);
    RobotomyRequestForm(const std::string name);
    RobotomyRequestForm(const std::string name, int sign_grade, int exec_grade);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &old);
    ~RobotomyRequestForm();

    bool isSigned(void)const;
    int getSignGrade(void)const;
    int getExecGrade(void)const;
    const std::string getName(void)const;

    void beSigned(Bureaucrat &candidate);
    
	class GradeTooHighException: public std::exception{
		public:
			virtual const char *what()const throw();
	};
	class GradeTooLowException: public std::exception{
		public:
			virtual const char *what()const throw();
	};

private:
    const std::string _name;
    int _sign_grade;
    int _exec_grade;
    bool _signed;
};


#endif