#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): _name("default"), _sign_grade(1), _exec_grade(2), _signed(false){
    std::cout<<"RobotomyRequestForm "<<this->_name<<" default constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &old): _name(old.getName() + "_copy"){
    std::cout<<"RobotomyRequestForm "<<this->_name<<" copy constructor called"<<std::endl;
    *this = old;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name): _name(name), _sign_grade(1), _exec_grade(2), _signed(false){
    std::cout<<"RobotomyRequestForm "<<this->_name<<" custom constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(int sign_grade, int exec_grade): _name("default"), _sign_grade(sign_grade),
   _exec_grade(exec_grade), _signed(false){
    std::cout<<"RobotomyRequestForm "<<this->_name<<" custom constructor called"<<std::endl;   
    if (sign_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (sign_grade > MIN_GRADE)
        throw GradeTooLowException();
    if (exec_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (exec_grade > MIN_GRADE)
        throw GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name, int sign_grade, int exec_grade): _name(name), _sign_grade(sign_grade),
   _exec_grade(exec_grade), _signed(false){
    std::cout<<"RobotomyRequestForm "<<this->_name<<" custom constructor called"<<std::endl;   
    if (sign_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (sign_grade > MIN_GRADE)
        throw GradeTooLowException();
    if (exec_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (exec_grade > MIN_GRADE)
        throw GradeTooLowException();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &old){
    std::cout<<"RobotomyRequestForm "<<this->_name<<" assignment operator called"<<std::endl;
	if (this == &old)
		return(*this);
	this->_sign_grade = old.getSignGrade();
	this->_exec_grade = old.getExecGrade();
	return(*this);       
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout<<"RobotomyRequestForm "<<this->_name<<" default destructor called"<<std::endl;
}

bool RobotomyRequestForm::isSigned()const{
    return(this->_signed);
}

int RobotomyRequestForm::getSignGrade()const
{
	return(this->_sign_grade);
}

int RobotomyRequestForm::getExecGrade()const
{
	return(this->_sign_grade);
}

const std::string RobotomyRequestForm::getName()const
{
	return(this->_name);
}

void RobotomyRequestForm::beSigned(Bureaucrat &candidate){
    if (candidate.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    if (candidate.getGrade() < MAX_GRADE)
        throw GradeTooHighException();
    else if (this->isSigned() == false)
    {
        this->_signed = true;
		std::cout<<"RobotomyRequestForm "<<this->getName()<<" was signed by "<<candidate.getName()<<std::endl;
	}
	else
		std::cout<<candidate.getName()<<"can't sign an already signed RobotomyRequestForm"<<std::endl;
}


const char *RobotomyRequestForm::GradeTooHighException::what()const throw(){
	return("\033[1:34mGrade too high!\033[0m");
}

const char *RobotomyRequestForm::GradeTooLowException::what()const throw(){
	return("\033[1:34mGrade too low!\033[0m");
}