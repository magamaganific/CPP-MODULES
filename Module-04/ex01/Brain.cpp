#include "Brain.hpp"
#include <iostream>

Brain::Brain(void){
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain &old){
	*this->_ideas = old.getIdeas();
}

Brain &Brain::operator=(const Brain &old){
	if (this == &old)
		return(*this);
	*this->_ideas = old.getIdeas();
	return (*this);
}

std::string Brain::getIdeas(void) const{
	return (*this->_ideas);
}

Brain::~Brain(void){
	std::cout << "Brain destructed" << std::endl;
}