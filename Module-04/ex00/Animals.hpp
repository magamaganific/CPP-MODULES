#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal{
public:
	Animal();
	Animal(const Animal &old);
	Animal &operator=(const Animal &old);
	~Animal();

	virtual void  makeSound() = 0;
protected:
	std::string type;
};

class Dog: public Animal{
public:
	Dog();
	Dog(const Dog &old);
	Dog &operator=(const Dog &old);
	~Dog();

	void makeSound() {std::cout << "Barking like the dog I am" << std::endl;}
};

class Cat: public Animal{
public:
	Cat();
	Cat(const Cat &old);
	Cat &operator=(const Cat &old);
	~Cat();

	void makeSound() {std::cout << "meowing like the cat I am" << std::endl;}
};

#endif