#include "Brain.hpp"
#include <iostream>

Brain::Brain(void){
	std::cout << "Brain constructed." << std::endl;
}

Brain::Brain(const Brain &old){
	std::cout << "Brain copy constructed." << std::endl;
	*this = old;
}

Brain &Brain::operator=(const Brain &old){
	std::copy(old._ideas, old._ideas + 100, this->_ideas);
	std::cout << "Assignment operator called." << std::endl;
	return (*this);
}

std::string const &Brain::getIdea(int const &ind) const{
	if (ind >= 0 && ind < 100)
		return(this->_ideas[ind]);
	return(this->_ideas[ind]);
}

void Brain::setIdea(const std::string &idea, int const &ind){
	if (ind >= 0 && ind < 100)
		this->_ideas[ind] = idea;
}

Brain::~Brain(void){
	std::cout << "Brain destructed" << std::endl;
}