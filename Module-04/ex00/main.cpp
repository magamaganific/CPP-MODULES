#include "Animals.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete i;
	delete j;

	std::cout << "\n\n---------------------------WRONG ANIMAL------------------------------" << std::endl;
	
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* notcat = new WrongCat();

	std::cout << notcat->getType() << " " << std::endl;
	notcat->makeSound();
	wrong->makeSound();

	delete wrong;
	delete notcat;
	return 0;
}