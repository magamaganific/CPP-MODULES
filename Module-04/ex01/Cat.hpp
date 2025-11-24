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
	std::string const &getType(void) const;
	void setType(std::string const &type);

	Brain &getBrain(void) const;
	void setBrain(Brain const &brain);
private:
	Brain *_catBrain;
};

# endif