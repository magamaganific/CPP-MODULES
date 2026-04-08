#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(1)
{
	if (_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (_grade > MIN_GRADE)
		throw GradeTooLowException();
	std::cout<<"Bureaucrat "<<this->_name<< " default constructor called with grade "
	<<this->_grade<<std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	std::cout<<"Bureaucrat "<<this->_name<< " constructor called with grade "
	<<this->_grade<<std::endl;
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &old): _name(old.getName() + "_copy")
{
	std::cout<<"Bureaucrat "<<this->_name<< " copy constructor called with grade "
	<<this->_grade<<std::endl;
	*this = old;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &old)
{
	std::cout<<"Bureaucrat "<<this->_name<<" assignment operator called"<<std::endl;
	if (this == &old)
		return(*this);
	this->_grade = old.getGrade();
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat "<<this->_name<< " destructor called"<<std::endl;
}

int Bureaucrat::getGrade()const
{
	return(this->_grade);
}

const std::string &Bureaucrat::getName()const
{
	return(this->_name);
}

void Bureaucrat::increment()
{
	this->_grade = this->_grade -1;
	if (this->_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (this->_grade > MIN_GRADE)
		throw GradeTooLowException();
	std::cout<<"Bureaucrat "<<this->_name<<" incremented"<<std::endl;
}

void Bureaucrat::decrement()
{
	this->_grade = this->_grade + 1;
	if (this->_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (this->_grade > MIN_GRADE)
		throw GradeTooLowException();
	std::cout<<"Bureaucrat "<<this->_name<<" decremented"<<std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out<<b.getName()<<", bureaucrat grade "<<b.getGrade()<<"."<<std::endl;
	return(out);
}

const char *Bureaucrat::GradeTooHighException::what()const throw(){
	return("\033[1:34mGrade too high!\033[0m");
}

const char *Bureaucrat::GradeTooLowException::what()const throw(){
	return("\033[1:34mGrade too low!\033[0m");
}

void Bureaucrat::signForm(AForm &form){
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm &form){
	form.execute(*this);
}