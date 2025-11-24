#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal{
public:
	explicit Animal();
	Animal(std::string const &type);
	Animal(const Animal &old);
	Animal &operator=(const Animal &old);
	virtual ~Animal();

	virtual void  makeSound() const;
	std::string const &getType(void) const;
	void setType(std::string const &type);
protected:
	std::string type;
};
#endif