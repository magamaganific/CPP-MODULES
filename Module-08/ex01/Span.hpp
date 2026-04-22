#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <iostream>
# include <string>
# include <exception>

class Span{
public:
	Span();
	Span(int N);
	Span(const Span &old);
	Span &operator=(const Span &old);

	void addNumber(int num)const;
	int shortestSpan()const;
	int longestSpan()const;

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
	std::vector<int> _nums;
};

#endif