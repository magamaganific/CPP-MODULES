#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>


class Animal{
public:
	explicit Animal();
	Animal(const Animal &old);
	Animal &operator=(const Animal &old);
	virtual ~Animal();

	virtual void  makeSound() const  = 0;
	std::string getType(void) const;
protected:
	std::string type;
};
#endif