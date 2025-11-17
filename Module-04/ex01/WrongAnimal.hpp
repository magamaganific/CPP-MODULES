#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <iostream>

class WrongAnimal{
public:
	explicit WrongAnimal();
	WrongAnimal(const WrongAnimal &old);
	WrongAnimal &operator=(const WrongAnimal &old);
	virtual ~WrongAnimal();

	virtual void  makeSound() const;
	std::string getType(void) const;
protected:
	std::string type;
};
#endif