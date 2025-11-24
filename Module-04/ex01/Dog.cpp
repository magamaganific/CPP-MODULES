#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << this->type << " default constructor called" << std::endl;
	this->_brain = new Brain;
}

Dog::Dog(const Dog &old) : Animal(old){
	std::cout << this->type << " copy constructor called" << std::endl;
	this->_brain = new Brain(*old._brain);
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

Brain &Dog::getBrain(void)const{
	return(*this->_brain);	
}

void Dog::setBrain(Brain const &brain){
	*this->_brain = brain;
}



Dog::~Dog(){
	std::cout << this->type << " destructor called" << std::endl;
	delete this->_brain;
}
