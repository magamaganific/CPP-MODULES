#include "Animals.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define CAT "\033[38;5;202m"
#define DOG "\033[38;5;42m"
#define WRNG "\033[38;5;184m"
#define NONE "\033[m"

int main()
{
	{
	std::cout << DOG << std::endl;
	const Animal* j = new Dog();
	std::cout << CAT << std::endl;
	const Animal* i = new Cat();
	std::cout << NONE << std::endl;

	std::cout << DOG;
	std::cout << j->getType() << " " << std::endl;
	std::cout << CAT;
	std::cout << i->getType() << " \n" << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << DOG;
	j->makeSound();
	std::cout << NONE;
	std::cout << std::endl;
	
	std::cout << CAT << std::endl;
	delete i;
	std::cout << DOG << std::endl;
	delete j;
	std::cout << NONE << std::endl;
	}
	{
	std::cout << "\n---------------------------WRONG ANIMAL------------------------------\n" << std::endl;
	const WrongAnimal* wrong = new WrongAnimal();
	std::cout << WRNG << std::endl;
	const WrongAnimal* notcat = new WrongCat();

	std::cout << notcat->getType() << " " << std::endl;
	notcat->makeSound();
	std::cout << NONE << std::endl;
	wrong->makeSound();

	delete wrong;
	std::cout << WRNG << std::endl;
	delete notcat;
	std::cout << NONE << std::endl;
	}
	std::cout << "\n---------------------------BRAIN CHECK------------------------------\n" << std::endl;
	{
	const Animal* j = new Dog();
	std::cout << CAT << std::endl;
	const Animal* i = new Cat();
	std::cout << NONE << std::endl;
	delete j;//should not create a leak
	std::cout << CAT << std::endl;
	delete i;
	std::cout << NONE << std::endl;
	}
	return 0;
}