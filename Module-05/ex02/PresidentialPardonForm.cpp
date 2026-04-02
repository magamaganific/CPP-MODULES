#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): _name("default"), _sign_grade(1), _exec_grade(2), _signed(false){
    std::cout<<"PresidentialPardonForm "<<this->_name<<" default constructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &old): _name(old.getName() + "_copy"){
    std::cout<<"PresidentialPardonForm "<<this->_name<<" copy constructor called"<<std::endl;
    *this = old;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name): _name(name), _sign_grade(1), _exec_grade(2), _signed(false){
    std::cout<<"PresidentialPardonForm "<<this->_name<<" custom constructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(int sign_grade, int exec_grade): _name("default"), _sign_grade(sign_grade),
   _exec_grade(exec_grade), _signed(false){
    std::cout<<"PresidentialPardonForm "<<this->_name<<" custom constructor called"<<std::endl;   
    if (sign_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (sign_grade > MIN_GRADE)
        throw GradeTooLowException();
    if (exec_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (exec_grade > MIN_GRADE)
        throw GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name, int sign_grade, int exec_grade): _name(name), _sign_grade(sign_grade),
   _exec_grade(exec_grade), _signed(false){
    std::cout<<"PresidentialPardonForm "<<this->_name<<" custom constructor called"<<std::endl;   
    if (sign_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (sign_grade > MIN_GRADE)
        throw GradeTooLowException();
    if (exec_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (exec_grade > MIN_GRADE)
        throw GradeTooLowException();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &old){
    std::cout<<"PresidentialPardonForm "<<this->_name<<" assignment operator called"<<std::endl;
	if (this == &old)
		return(*this);
	this->_sign_grade = old.getSignGrade();
	this->_exec_grade = old.getExecGrade();
	return(*this);       
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout<<"PresidentialPardonForm "<<this->_name<<" default destructor called"<<std::endl;
}

bool PresidentialPardonForm::isSigned()const{
    return(this->_signed);
}

int PresidentialPardonForm::getSignGrade()const
{
	return(this->_sign_grade);
}

int PresidentialPardonForm::getExecGrade()const
{
	return(this->_sign_grade);
}

const std::string PresidentialPardonForm::getName()const
{
	return(this->_name);
}

void PresidentialPardonForm::beSigned(Bureaucrat &candidate){
    if (candidate.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    if (candidate.getGrade() < MAX_GRADE)
        throw GradeTooHighException();
    else if (this->isSigned() == false)
    {
        this->_signed = true;
		std::cout<<"PresidentialPardonForm "<<this->getName()<<" was signed by "<<candidate.getName()<<std::endl;
	}
	else
		std::cout<<candidate.getName()<<"can't sign an already signed PresidentialPardonForm"<<std::endl;
}


const char *PresidentialPardonForm::GradeTooHighException::what()const throw(){
	return("\033[1:34mGrade too high!\033[0m");
}

const char *PresidentialPardonForm::GradeTooLowException::what()const throw(){
	return("\033[1:34mGrade too low!\033[0m");
}