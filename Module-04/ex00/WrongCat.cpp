#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	type = "WrongCat";
	std::cout << this->type << " default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &old) : WrongAnimal(old){
	std::cout << this->type << " copy constructor called" << std::endl;
	*this = old;
}

WrongCat &WrongCat::operator=(const WrongCat &old){
	std::cout << this->type << "assignment operator called" << std::endl;
	if (this == &old)
		return (*this);
	this->type = old.type;
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << this->type << " destructor called" << std::endl;
}