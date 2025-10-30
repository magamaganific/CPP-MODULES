#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	int size = 20;
	Zombie *horde = zombieHorde(20, "Daniel");

	for (int i = 0; i < size; i++)
		horde[i].announce();
	return(0);
}