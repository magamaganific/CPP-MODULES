#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animals.hpp"
# include "Brain.hpp"

class Cat: public Animal{
public:
	Cat();
	Cat(const Cat &old);
	Cat &operator=(const Cat &old);
	~Cat();

	void makeSound() const;
private:
	Brain *_catBrain;
};

# endif