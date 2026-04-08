#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("Shrubbery Creation Form", 145, 137){
	std::cout <<this->getName()<<" default constructor called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &old): AForm(old){
	std::cout <<this->getName()<<" copy constructor called"<<std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &old){
	std::cout <<this->getName()<<" assignment operator called"<<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout <<this->getName()<<" default destructor called"<<std::endl;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &s)
{
	out<<s.getName()<<std::endl;
	out<<s.getSignGrade()<<std::endl;
	out<<s.getExecGrade()<<std::endl;
	return(out);
}

void ShrubberyCreationForm::executeForm(Bureaucrat &target){
	if (this->isSigned() == false)
		throw NotSignedException();
	else if (target.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	else{
		std::cout <<target.getName()<<" executed "<<this->getName()<<std::endl;
		std::ofstream ofs;
		ofs.open(target.getName() + "_shrubbery", std::ofstream::trunc | std::ofstream::out);
		ofs<<;
	}
}