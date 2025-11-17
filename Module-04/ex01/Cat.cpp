#include "Cat.hpp"

Cat::Cat() : Animal(){
	type = "Cat";
	std::cout << this->type << " default constructor called" << std::endl;
	this->_brain = new Brain;
}

Cat::Cat(const Cat &old){
	std::cout << this->type << " copy constructor called" << std::endl;
	*this = old;
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
	delete this->_brain;
}