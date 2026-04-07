#include " ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	Form("Shrubbery Creation Form", 145, 137){
	std::cout <<this->getName()<<" default constructor called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &old): Form(old){
	std::cout <<this->getName()<<" copy constructor called"<<std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &old){
	std::cout <<this->getName()<<" assignment operator called"<<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout <<this->getName()<<" default destructor called"<<std::endl;
}

void ShrubberyCreationForm::executeForm(Bureaucrat &target){
	if (this->isSigned() == false)
		std::cout <<this->getName()<<" cannot be executed: Isn't signed"<<std::endl;
	else if (target.getGrade() > this->getExecGrade())
	{
		std::cout <<this->getName()<<" cannot be executed:"<<std::endl;
		throw GradeTooLowException();
	}
	else{
		std::cout <<target.getName()<<" executed "<<this->getName()<<std::endl;
		int fd;
	}
}