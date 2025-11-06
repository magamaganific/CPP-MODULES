#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap Marcus =  ClapTrap("Marcus");

	Marcus.attack("Megalodon");
	Marcus.takeDamage(5);
	Marcus.beRepaired(2);
}