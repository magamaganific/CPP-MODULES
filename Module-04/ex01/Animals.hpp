#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
#include "Brain.hpp"

class Animal{
public:
	explicit Animal();
	Animal(const Animal &old);
	Animal &operator=(const Animal &old);
	virtual ~Animal();

	virtual void  makeSound() const;
	std::string const &getType(void) const;
	void setType(std::string const &type);

	virtual Brain &getBrain(void) const = 0;
protected:
	std::string type;
};
#endif