#include "zombie.class.hpp"

Zombie *newZombie(std::string name);

void randomChump(std::string name);

int main(void)
{
	Zombie *z = newZombie("Alex");
	z->announce();
	randomChump("Daniel");
}