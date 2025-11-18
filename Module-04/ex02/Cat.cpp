#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->type = "Cat";
	std::cout << this->type << " default constructor called" << std::endl;
	this->_catBrain = new Brain;
}

Cat::Cat(const Cat &old): Animal(old){
	std::cout << this->type << " copy constructor called" << std::endl;
	delete this->_catBrain;
	this->_catBrain = new Brain(*old._catBrain);
}

Cat &Cat::operator=(const Cat &old){
	std::cout << this->type << "assignment operator called" << std::endl;
	if (this == &old)
		return (*this);
	this->type = old.type;
	return (*this);
}

void Cat::makeSound() const{
	std::cout << this->type << ": Meowing like the cat I am" << std::endl;
}

Cat::~Cat(){
	std::cout << this->type << " destructor called" << std::endl;
	delete this->_catBrain;
}