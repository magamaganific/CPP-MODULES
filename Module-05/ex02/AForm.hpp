#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"
# include <stdbool.h>

class Bureaucrat;

class AForm{
public:
    AForm();
    AForm(const AForm &old);
    AForm(int sign_grade, int exec_grade);
    AForm(const std::string name);
    AForm(const std::string name, int sign_grade, int exec_grade);
    AForm &operator=(const AForm &old);
    ~AForm();

    bool isSigned(void)const;
    int getSignGrade(void)const;
    int getExecGrade(void)const;
    const std::string getName(void)const;

    void beSigned(Bureaucrat &candidate);
	virtual void execute(Bureaucrat const &exec)const = 0;
    
	class GradeTooHighException: public std::exception{
		public:
			virtual const char *what()const throw();
	};
	class GradeTooLowException: public std::exception{
		public:
			virtual const char *what()const throw();
	};
	class NotSignedException: public std::exception{
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