#include "Animals.hpp"
#include <iostream>

Animal::Animal(){
	this->type = "Unidentified animal";
	std::cout << this->type << " default constructor called" << std::endl;
}

Animal::Animal(const Animal &old): type() {
	std::cout << type << " copy constructor called" << std::endl;
	*this = old;
}

Animal &Animal::operator=(const Animal &old){
	std::cout << this->type << " assignment operator called" << std::endl;
	if (this == &old)
		return (*this);
	this->type = old.type;
	return (*this);
}

Animal::~Animal(){
	std::cout << this->type << " destructor called" << std::endl;
}

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

Dog::~Dog(){
	std::cout << this->type << " destructor called" << std::endl;
}

Cat::Cat() : Animal(){
	type = "Cat";
	std::cout << this->type << " default constructor called" << std::endl;
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

Cat::~Cat(){
	std::cout << this->type << " destructor called" << std::endl;
}