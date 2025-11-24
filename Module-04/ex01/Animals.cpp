#include "Animals.hpp"
#include <iostream>

Animal::Animal(){
	this->type = "Unidentified animal";
	std::cout << "Default [Animal] constructor called" << std::endl;
}

Animal::Animal(const Animal &old): type() {
	std::cout << "[Animal] copy constructor called" << std::endl;
	*this = old;
}

Animal &Animal::operator=(const Animal &old){
	std::cout << "[Animal] assignment operator called" << std::endl;
	if (this == &old)
		return (*this);
	this->type = old.type;
	return (*this);
}

void Animal::makeSound() const{
	std::cout << this->type << ", sound not found" << std::endl;
}

std::string const &Animal::getType(void) const{
	return(this->type);
}
void Animal::setType(const std::string &type){
	this->type = type;
}
Animal::~Animal(){
	std::cout << "[Animal] destructor called" << std::endl;
}