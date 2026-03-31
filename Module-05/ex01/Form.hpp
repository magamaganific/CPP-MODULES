#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Form: public Bureaucrat{
public:
    Form();
    Form(const Form &old);
    Form &operator=(const Form &old)
    ~Form();

    int getSignGrade(void)const;
    int getExecGrade(void)const;
    const std::string getName(void)const;

private:
    int _exec_grade;
    int _sign_grade;
    bool _signed;
    const std::string _name;
};


#endif