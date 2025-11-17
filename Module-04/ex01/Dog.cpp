#include "Dog.hpp"

Dog::Dog() : Animal(){
	type = "Dog";
	std::cout << this->type << " default constructor called" << std::endl;
}

Dog::Dog(const Dog &old){
	std::cout << this->type << " copy constructor called" << std::endl;
	*this = old;
}

Dog &Dog::operator=(const Dog &old){
	std::cout << this->type << "assignment operator called" << std::endl;
	if (this == &old)
		return (*this);
	this->type = old.type;
	return (*this);
}

void Dog::makeSound() const{
	std::cout << this->type << ": Barking like the dog I am" << std::endl;
}

Dog::~Dog(){
	std::cout << this->type << " destructor called" << std::endl;
}
