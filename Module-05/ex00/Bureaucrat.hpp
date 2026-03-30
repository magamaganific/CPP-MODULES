#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# define MAX_GRADE 1
# define MIN_GRADE 150
# include <iostream>
# include <exception>
# include <string>

class Bureaucrat{
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &old);
	Bureaucrat &operator=(const Bureaucrat &old);
	~Bureaucrat();

	const std::string &getName(void) const;
	int getGrade(void) const;
	void increment(void);
	void decrement(void);

	class GradeTooHighException: public std::exception{
		public:
			virtual const char *what()const throw();
	};
	class GradeTooLowException: public std::exception{
		public:
			virtual const char *what()const throw();
	};
private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
#endif