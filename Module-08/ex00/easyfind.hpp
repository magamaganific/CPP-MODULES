#include <algorithm>
#include <iterator>
#include <iostream>
#include <exception>

class NotFoundException: public std::exception {
	public:
		virtual const char *what() const throw(){
			return("Not Found");
		}
};

template <typename T>
typename T::iterator easyfind(T &ints, int n){
	typename T::iterator it;
	it = find(ints.begin(), ints.end(), n);
	if (it == ints.end())
		throw (NotFoundException());
	return(it);
}