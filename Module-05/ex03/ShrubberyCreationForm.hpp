#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>
# include <stdbool.h>

class AForm;

class ShrubberyCreationForm: public AForm{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &old);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &old);
	~ShrubberyCreationForm();

	const std::string &getTarget()const;
	void execute(Bureaucrat const &exec)const;
private:
	std::string _target;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &s); 
#endif