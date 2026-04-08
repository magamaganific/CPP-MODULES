#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm():
	AForm("Robotomy Request Form", 72, 45), _target("default"){
	std::cout <<this->getName()<<" default constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("Robotomy Request Form", 72, 45), _target(target){
	std::cout <<this->getName()<<" custom constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &old): AForm(old){
	std::cout <<this->getName()<<" copy constructor called"<<std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &old){
	std::cout <<this->getName()<<" assignment operator called"<<std::endl;
	if (this != &old)
		this->_target = old._target;
	return(*this); 
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout <<this->getName()<<" default destructor called"<<std::endl;
}

const std::string &RobotomyRequestForm::getTarget()const{
	return(this->_target);
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &s)
{
	out<<s.getName()<<std::endl;
	out<<s.getSignGrade()<<std::endl;
	out<<s.getExecGrade()<<std::endl;
	return(out);
}

void RobotomyRequestForm::execute(Bureaucrat const &exec)const{
	if (this->isSigned() == false)
		throw NotSignedException();
	else if (exec.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	else{
		std::cout<<"DRILLING NOISES"<<std::endl;
		if ((rand() % 2))
			std::cout<<this->getTarget()<<" has been succesfully Robotomized"<<std::endl;
		else
			std::cout<<this->getTarget()<<" Robotomy failed"<<std::endl;
	}
}