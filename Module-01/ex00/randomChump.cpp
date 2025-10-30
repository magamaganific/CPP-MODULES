#include "zombie.class.hpp"

void randomChump(std::string name)
{
	Zombie chump = Zombie(name);
	chump.announce();
}