#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm():
	AForm("Robotomy Request Form", 25, 5), _target("default"){
	std::cout <<this->getName()<<" default constructor called."<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("Robotomy Request Form", 25, 5), _target(target){
	std::cout <<this->getName()<<" custom constructor called."<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &old): AForm(old){
	std::cout <<this->getName()<<" copy constructor called."<<std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &old){
	std::cout <<this->getName()<<" assignment operator called."<<std::endl;
	if (this != &old)
		this->_target = old._target;
	return(*this); 
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout <<this->getName()<<" default destructor called."<<std::endl;
}

const std::string &PresidentialPardonForm::getTarget()const{
	return(this->_target);
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &s)
{
	out<<s.getName()<<std::endl;
	out<<s.getSignGrade()<<std::endl;
	out<<s.getExecGrade()<<std::endl;
	return(out);
}

void PresidentialPardonForm::execute(Bureaucrat const &exec)const{
	if (this->isSigned() == false)
		throw NotSignedException();
	else if (exec.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	else
		std::cout<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}
