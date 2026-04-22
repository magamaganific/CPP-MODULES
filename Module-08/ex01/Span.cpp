#include "Span.hpp"

Span::Span(): _N(0){
}

Span::Span(int N): _N(N){
}

Span::Span(const Span &old){
	*this = old;
}

Span &Span::operator=(const Span &old){
	this->_nums.clear();
	this->_N = old._N;
	std::list<int>::const_iterator it;

	for (it = old._nums.begin(); it !=old._nums.end(); it++)
		this->_nums.push_front(*it);
}

Span::~Span(){
}

void Span::addNumber(int num){
	if (this->_nums.size() + 1 <= this->_N)
		this->_nums.push_front(num);
}

int Span::longestSpan(){
	std::list<int>::const_iterator i;
	std::list<int>::const_iterator j;

}