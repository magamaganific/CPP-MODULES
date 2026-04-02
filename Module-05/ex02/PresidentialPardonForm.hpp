#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Bureaucrat.hpp"
#include <stdbool.h>

class Bureaucrat;

class PresidentialPardonForm{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &old);
    PresidentialPardonForm(int sign_grade, int exec_grade);
    PresidentialPardonForm(const std::string name);
    PresidentialPardonForm(const std::string name, int sign_grade, int exec_grade);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &old);
    ~PresidentialPardonForm();

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