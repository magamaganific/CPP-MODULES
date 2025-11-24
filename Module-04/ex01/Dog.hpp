#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animals.hpp"
# include "Brain.hpp"

class Dog: public Animal{
public:
	Dog();
	Dog(const Dog &old);
	Dog &operator=(const Dog &old);
	~Dog();

	void makeSound() const;

	Brain &getBrain(void) const;
	void setBrain(Brain const &brain);
private:
	Brain *_brain;
};

# endif