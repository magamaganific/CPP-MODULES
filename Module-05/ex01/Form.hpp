#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
#include <stdbool.h>

class Form{
public:
    Form();
    Form(const Form &old);
    Form(int sign_grade, int exec_grade);
    Form(const std::string name);
    Form(const std::string name, int sign_grade, int exec_grade);
    Form &operator=(const Form &old)
    ~Form();

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
    int _exec_grade;
    int _sign_grade;
    bool _signed;
    const std::string _name;
};


#endif