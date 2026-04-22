#include "Span.hpp"

Span::Span(): _N(0){
}

Span::Span(unsigned int N): _N(N){
	this->_nums.reserve(N);
}

Span::Span(const Span &old){
	*this = old;
}

Span &Span::operator=(const Span &old){
	this->_nums.clear();
	this->_N = old._N;
	std::vector<int>::const_iterator it;

	for (it = old._nums.begin(); it != old._nums.end(); it++)
		this->_nums.push_back(*it);
	return(*this);
}

Span::~Span(){
}

void Span::addNumber(int num){
	if (this->_nums.size() + 1 < this->_nums.max_size())
		this->_nums.push_back(num);
}

int Span::longestSpan(){
	std::vector<int>::const_iterator i;
	std::vector<int>::const_iterator j;
	int span = 0;
	int longest = 0;

	for (i = this->_nums.begin(); i != this->_nums.end(); i++)
	{
		for (j = i; j != this->_nums.end(); j++){
			span = *i - *j;
			if (span < 0)
				span *= -1;
			if (span > longest)
				longest = span;
		}
	}
	return(longest);
}

int Span::shortestSpan(){
	std::vector<int>::const_iterator i = this->_nums.begin();
	std::vector<int>::const_iterator j = i + 1;
	int span = 0;
	int shortest = *i - *j;

	if (shortest < 0)
		shortest *= -1;
	for (i = this->_nums.begin(); i != this->_nums.end(); i++)
	{
		for (j = i + 1; j != this->_nums.end(); j++){
			span = *i - *j;
			if (span < 0)
				span *= -1;
			if (span < shortest)
				shortest = span;
		}
	}
	return(shortest);
}
