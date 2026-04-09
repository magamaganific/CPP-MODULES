#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("Shrubbery Creation Form", 145, 137), _target("default"){
	std::cout <<this->getName()<<" default constructor called."<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("Shrubbery Creation Form", 145, 137), _target(target){
	std::cout <<this->getName()<<" custom constructor called."<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &old): AForm(old){
	std::cout <<this->getName()<<" copy constructor called."<<std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &old){
	std::cout <<this->getName()<<" assignment operator called."<<std::endl;
	if (this != &old)
		this->_target = old._target;
	return(*this); 
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout <<this->getName()<<" default destructor called."<<std::endl;
}

const std::string &ShrubberyCreationForm::getTarget()const{
	return(this->_target);
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &s)
{
	out<<s.getName()<<std::endl;
	out<<s.getSignGrade()<<std::endl;
	out<<s.getExecGrade()<<std::endl;
	return(out);
}

void ShrubberyCreationForm::execute(Bureaucrat const &exec)const{
	if (exec.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->isSigned() == false)
		throw NotSignedException();
	else{
		std::cout <<exec.getName()<<" executed "<<this->getName()<<"."<<std::endl;
		std::ofstream ofs;
		std::string filename =this->getTarget()+ "_shrubbery";
		ofs.open(filename.c_str() , std::ofstream::trunc | std::ofstream::out);
		ofs<<"                                                                   ☆\n\n";
		ofs<<"     ☆\n\n";
		ofs<<"                         _ ❈ ~ ,❈ , ~  ✧ ❈\n";
		ofs<<"                    _~(       ✿            ` ~  ´  ¨   * ❈\n";
		ofs<<"                  &     ✧              ✽                   * ❈\n";
		ofs<<"                 &   ✽     ✧               ✿                  3           ☆\n";
		ofs<<"           c~º~%ºg.                              ✧      ❀       &\n";
		ofs<<"        C*º       ❀ ❈    \"I drew this tree\"                      )\n";
		ofs<<"       S   ✧         3            -SheDaVinci     ✽      c~º~%ºg.\n";
		ofs<<"      .❈✧         ✽   ~           ✽                  C*º  ❀    ✧ º\n";
		ofs<<"        (8   ❀      )       ❀                     3S          ✿  3\n";
		ofs<<"          &       3                      ❀    ✿  .¨    ❀       ❈~\n";
		ofs<<"         S( ¨ ^ ¨      ❀      ✷ ⁔   ✶         ︵  8          )\n";
		ofs<<"          ✧❀    ✿       ⁔     _// ❀ _/ ,¨ ✿ ◠v/ *  &    ❀  3\n";
		ofs<<"           *8&*     ❀ ✯// ❀/ /         .✿  , / ✿  ✧ .¨ ^ ¨ \n";
		ofs<<"               & &. ✧.❀\\\\ /             V¨´,´❀  &··¨\n";
		ofs<<"                   ¨❈ ¨>|V/░    |\\       /´.✧··¨\n";
		ofs<<"                         \\░░/   /,\\\\ \\ |/\n";
		ofs<<"                           \\\\   ||  \\\\ \\\\\n";
		ofs<<"                           /░¡  ||·· || |\\\n";
		ofs<<"    ☆                     :\\░ \\  \\\\ // /  \\\n";
		ofs<<"                         /░|░░ \\. \\V/ /   :|\n";
		ofs<<"                       ,´/░/░░░!\\'* /  .:/ |\\\n";
		ofs<<"´´´´´```'''\"´'´´`´`´´´'``''`´```´´´´´```'''\"´'´´`´`´´´'``''`´```´`'´`´´`´'''\"\n\n";
	}
}