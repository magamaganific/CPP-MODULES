#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animals.hpp"

class Dog: public Animal{
public:
	Dog();
	Dog(const Dog &old);
	Dog &operator=(const Dog &old);
	~Dog();

	void makeSound() const;
};

# endif