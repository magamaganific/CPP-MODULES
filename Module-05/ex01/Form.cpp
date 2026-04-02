#include "Form.hpp"

Form::Form(): _name("default"), _sign_grade(1), _exec_grade(2), _signed(FALSE){
    std::cout<<"Form "<<this->_name<<" default constructor called"<<std::endl;
}

Form::Form(const Form &old): _name(old->getName() + "_copy"){
    std::cout<<"Form "<<this->_name<<" copy constructor called"<<std::endl;
    *this = old;
}

Form::Form(const std::string name): _name(name), _sign_grade(1), _exec_grade(2), _signed(FALSE){
    std::cout<<"Form "<<this->_name<<" custom constructor called"<<std::endl;
}

Form::Form(int sign_grade, int exec_grade): _name("default"), _sign_grade(sign_grade)
   _exec_grade(exec_grade), _signed(FALSE){
    std::cout<<"Form "<<this->_name<<" custom constructor called"<<std::endl;   
    if (sign_grade < MAX_GRADE)
        throw (GradeTooHighException);
    else if (sign_grade > MIN_GRADE)
        throw (GradeTooLowException);
    if (exec_grade < MAX_GRADE)
        throw (GradeTooHighException);
    else if (exec_grade > MIN_GRADE)
        throw (GradeTooLowException);
}

Form::Form(const std::string name, int sign_grade, int exec_grade): _name(name), _sign_grade(sign_grade)
   _exec_grade(exec_grade), _signed(FALSE){
    std::cout<<"Form "<<this->_name<<" custom constructor called"<<std::endl;   
    if (sign_grade < MAX_GRADE)
        throw (GradeTooHighException);
    else if (sign_grade > MIN_GRADE)
        throw (GradeTooLowException);
    if (exec_grade < MAX_GRADE)
        throw (GradeTooHighException);
    else if (exec_grade > MIN_GRADE)
        throw (GradeTooLowException);
}

Form &Form::operator=(const Form &old){
    std::cout<<"Form "<<this->_name<<" assignment operator called"<<std::endl;
	if (this == &old)
		return(*this);
	this->_grade = old.getGrade();
	return(*this);       
}

Form::~Form(){
    std::cout<<"Form "<<this->_name<<" default destructor called"<<std::endl;
}

bool Form::isSigned()const{
    return(this->_signed);
}

int Form::getSignGrade()const
{
	return(this->_sign_grade);
}

int Form::getExecGrade()const
{
	return(this->_sign_grade);
}

const std::string &Form::getName()const
{
	return(this->_name);
}

void Form::beSigned(Bureaucrat &candidate){
    if (candidate)
}