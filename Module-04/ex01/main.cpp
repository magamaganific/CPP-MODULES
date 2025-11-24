#include "Animals.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define CAT "\033[38;5;202m"
#define DOG "\033[38;5;42m"
#define WRNG "\033[38;5;184m"
#define NONE "\033[m"
#define AMOUNT 20

void fill_dog_brain(Brain *dogbrain)
{
	for (int i = 0; i < 100; i++)
	{
		dogbrain->setIdea("DOG ", i);
	}
}

void fill_cat_brain(Brain *catbrain)
{
	for (int i = 0; i < 100; i++)
	{
		catbrain->setIdea("CAT ", i);
	}
}

void print_cat_ideas(Brain *catbrain)
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << catbrain->getIdea(i);
	}
	std::cout << std::endl;
}

void print_dog_ideas(Brain *dogbrain)
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << dogbrain->getIdea(i);
	}
	std::cout << std::endl;
}

int main()
{
	{
	std::cout << "\n---------------------------BRAIN CHECK------------------------------\n" << std::endl;
	const Animal *cat = new Cat();
	const Animal *dog = new Dog();

	fill_dog_brain(&dog->getBrain());
	fill_cat_brain(&cat->getBrain());
	std::cout << CAT << "Cat Ideas:" << std::endl;
	print_cat_ideas(&cat->getBrain());
	std::cout << NONE << std::endl;
	std::cout << DOG << "Dog Ideas:" << std::endl;
	print_dog_ideas(&dog->getBrain());
	std::cout << NONE << std::endl;

	delete cat;
	delete dog;
	}
	{
	std::cout << "\n---------------------------LOTS OF ANIMALS------------------------------\n" << std::endl;
	const Animal *many[AMOUNT];
	for (int i = 0; i < AMOUNT ; i++)
	{
		if (i < AMOUNT / 2)
			many[i] = new Dog();
		else
			many[i] = new Cat();
	}
	std::cout << DOG << many[AMOUNT / 2 - 1]->getType() << std::endl;
	std::cout << CAT << many[AMOUNT / 2]->getType() << NONE << std::endl;
	Brain *dogbrain = &many[AMOUNT / 2 -1]->getBrain();
	dogbrain->setIdea("Woof", 1);
	std::cout << DOG << many[AMOUNT / 2 - 1]->getType() << " idea: " << dogbrain->getIdea(1) << std::endl;
	Brain *catbrain = &many[AMOUNT / 2]->getBrain();
	catbrain->setIdea("Meow", 1);
	std::cout << CAT << many[AMOUNT / 2]->getType() << " idea: " << catbrain->getIdea(1) << std::endl;
	std::cout << NONE << std::endl;
	for (int i = 0; i < AMOUNT; i++)
	{
		delete many[i];
	}
	}
	return 0;
}