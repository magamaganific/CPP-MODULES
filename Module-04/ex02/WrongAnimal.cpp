#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(){
	this->type = "Wrong animal";
	std::cout << "Default [WrongAnimal] constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &old): type() {
	std::cout << "[WrongAnimal] copy constructor called" << std::endl;
	*this = old;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &old){
	std::cout << "[WrongAnimal] assignment operator called" << std::endl;
	if (this == &old)
		return (*this);
	this->type = old.type;
	return (*this);
}

void WrongAnimal::makeSound() const{
	std::cout << this->type << ": Honking, for I am actually a goose." << std::endl;
}

std::string WrongAnimal::getType(void) const{
	return(this->type);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "[WrongAnimal] destructor called" << std::endl;
}