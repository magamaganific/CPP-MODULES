#include "Form.hpp"

Form::Form(): _name("default"), _sign_grade(1), _exec_grade(2), _signed(false){
    std::cout<<"Form "<<this->_name<<" default constructor called"<<std::endl;
}

Form::Form(const Form &old): _name(old.getName() + "_copy"){
    std::cout<<"Form "<<this->_name<<" copy constructor called"<<std::endl;
    *this = old;
}

Form::Form(const std::string name): _name(name), _sign_grade(1), _exec_grade(2), _signed(false){
    std::cout<<"Form "<<this->_name<<" custom constructor called"<<std::endl;
}

Form::Form(int sign_grade, int exec_grade): _name("default"), _sign_grade(sign_grade),
   _exec_grade(exec_grade), _signed(false){
    std::cout<<"Form "<<this->_name<<" custom constructor called"<<std::endl;   
    if (sign_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (sign_grade > MIN_GRADE)
        throw GradeTooLowException();
    if (exec_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (exec_grade > MIN_GRADE)
        throw GradeTooLowException();
}

Form::Form(const std::string name, int sign_grade, int exec_grade): _name(name), _sign_grade(sign_grade),
   _exec_grade(exec_grade), _signed(false){
    std::cout<<"Form "<<this->_name<<" custom constructor called"<<std::endl;   
    if (sign_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (sign_grade > MIN_GRADE)
        throw GradeTooLowException();
    if (exec_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (exec_grade > MIN_GRADE)
        throw GradeTooLowException();
}

Form &Form::operator=(const Form &old){
    std::cout<<"Form "<<this->_name<<" assignment operator called"<<std::endl;
	if (this == &old)
		return(*this);
	this->_sign_grade = old.getSignGrade();
	this->_exec_grade = old.getExecGrade();
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

const std::string Form::getName()const
{
	return(this->_name);
}

void Form::beSigned(Bureaucrat &candidate){
    if (candidate.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    if (candidate.getGrade() < MAX_GRADE)
        throw GradeTooHighException();
    else if (this->isSigned() == false)
    {
        this->_signed = true;
		std::cout<<"Form "<<this->getName()<<" was signed by "<<candidate.getName()<<std::endl;
	}
	else
		std::cout<<candidate.getName()<<"can't sign an already signed Form"<<std::endl;
}


const char *Form::GradeTooHighException::what()const throw(){
	return("\033[1:34mGrade too high!\033[0m");
}

const char *Form::GradeTooLowException::what()const throw(){
	return("\033[1:34mGrade too low!\033[0m");
}