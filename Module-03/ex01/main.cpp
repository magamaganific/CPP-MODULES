#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	{
	ClapTrap Marcus =  ClapTrap("Marcus");

	Marcus.attack("Megalodon");
	Marcus.takeDamage(5);
	Marcus.beRepaired(2);
	}
	{
	ScavTrap Catherine = ScavTrap("Catherine");
	Catherine.attack("Megalodon");
	Catherine.takeDamage(4);
	Catherine.beRepaired(2);
	}
}