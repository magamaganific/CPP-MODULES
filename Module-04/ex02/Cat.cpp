#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << this->type << " default constructor called" << std::endl;
	this->_brain = new Brain;
}

Cat::Cat(const Cat &old): Animal(old){
	std::cout << this->type << " copy constructor called" << std::endl;
	this->_brain = new Brain(*old._brain);
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

Brain &Cat::getBrain(void)const{
	return(*this->_brain);	
}

void Cat::setBrain(Brain const &brain){
	*this->_brain = brain;
}

Cat::~Cat(){
	std::cout << this->type << " destructor called" << std::endl;
	delete this->_brain;
}