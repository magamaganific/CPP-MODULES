#ifndef SPAN_HPP
# define SPAN_HPP
# include <list>
# include <iostream>
# include <string>
# include <exception>

class Span{
public:
	Span();
	Span(int N);
	Span(const Span &old);
	Span &operator=(const Span &old);

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

	class NoSpaceException: public std::exception{
		public:
			virtual const char *what()const throw();
	};
	class NoNumbersException: public std::exception{
		public:
			virtual const char *what()const throw();
	};
protected:
	int _N;
	std::list<int> _nums;
};

#endif