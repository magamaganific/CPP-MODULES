#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
public:
	WrongCat();
	WrongCat(const WrongCat &old);
	WrongCat &operator=(const WrongCat &old);
	~WrongCat();
};

# endif