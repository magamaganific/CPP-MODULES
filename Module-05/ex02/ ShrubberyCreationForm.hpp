#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Bureaucrat.hpp"
#include <stdbool.h>

class Bureaucrat;

class ShrubberyCreationForm{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &old);
    ShrubberyCreationForm(int sign_grade, int exec_grade);
    ShrubberyCreationForm(const std::string name);
    ShrubberyCreationForm(const std::string name, int sign_grade, int exec_grade);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &old);
    ~ShrubberyCreationForm();

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