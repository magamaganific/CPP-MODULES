#include "AForm.hpp"

AForm::AForm(): _name("default"), _sign_grade(1), _exec_grade(2), _signed(false){
    std::cout<<"AForm "<<this->_name<<" default constructor called"<<std::endl;
}

AForm::AForm(const AForm &old): _name(old.getName() + "_copy"){
    std::cout<<"AForm "<<this->_name<<" copy constructor called"<<std::endl;
    *this = old;
}

AForm::AForm(const std::string name): _name(name), _sign_grade(1), _exec_grade(2), _signed(false){
    std::cout<<"AForm "<<this->_name<<" custom constructor called"<<std::endl;
}

AForm::AForm(int sign_grade, int exec_grade): _name("default"), _sign_grade(sign_grade),
   _exec_grade(exec_grade), _signed(false){
    std::cout<<"AForm "<<this->_name<<" custom constructor called"<<std::endl;   
    if (sign_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (sign_grade > MIN_GRADE)
        throw GradeTooLowException();
    if (exec_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (exec_grade > MIN_GRADE)
        throw GradeTooLowException();
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade): _name(name), _sign_grade(sign_grade),
   _exec_grade(exec_grade), _signed(false){
    std::cout<<"AForm "<<this->_name<<" custom constructor called"<<std::endl;   
    if (sign_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (sign_grade > MIN_GRADE)
        throw GradeTooLowException();
    if (exec_grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (exec_grade > MIN_GRADE)
        throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &old){
    std::cout<<"AForm "<<this->_name<<" assignment operator called"<<std::endl;
	if (this == &old)
		return(*this);
	this->_sign_grade = old.getSignGrade();
	this->_exec_grade = old.getExecGrade();
	return(*this);       
}

AForm::~AForm(){
    std::cout<<"AForm "<<this->_name<<" default destructor called"<<std::endl;
}

bool AForm::isSigned()const{
    return(this->_signed);
}

int AForm::getSignGrade()const
{
	return(this->_sign_grade);
}

int AForm::getExecGrade()const
{
	return(this->_exec_grade);
}

const std::string AForm::getName()const
{
	return(this->_name);
}

void AForm::beSigned(Bureaucrat &candidate){
    if (candidate.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    if (candidate.getGrade() < MAX_GRADE)
        throw GradeTooHighException();
    else if (this->isSigned() == false)
    {
        this->_signed = true;
		std::cout<<"AForm "<<this->getName()<<" was signed by "<<candidate.getName()<<std::endl;
	}
	else
		std::cout<<candidate.getName()<<"can't sign an already signed AForm"<<std::endl;
}


const char *AForm::GradeTooHighException::what()const throw(){
	return("\033[1:34mGrade too high!\033[0m");
}

const char *AForm::GradeTooLowException::what()const throw(){
	return("\033[1:34mGrade too low!\033[0m");
}

const char *AForm::NotSignedException::what()const throw(){
	return("\033[1:34mForm not signed!\033[0m");
}