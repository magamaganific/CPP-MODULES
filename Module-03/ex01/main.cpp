#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	{
	ClapTrap Marcus =  ClapTrap("Marcus");

	Marcus.attack("Megalodon");
	std::cout << GREEN << Marcus.getName() << " hit points: " << Marcus.getHitPoints() << RESET << std::endl;
	Marcus.takeDamage(5);
	std::cout << GREEN << Marcus.getName() << " hit points: " << Marcus.getHitPoints() << RESET << std::endl;
	Marcus.beRepaired(2);
	std::cout << GREEN << Marcus.getName() << " hit points: " << Marcus.getHitPoints() << RESET << std::endl;
	}
	{
	ScavTrap Catherine = ScavTrap("Catherine");
	
	Catherine.attack("Megalodon");
	std::cout << GREEN << Catherine.getName() << " hit points: " << Catherine.getHitPoints() << RESET << std::endl;
	Catherine.takeDamage(5);
	std::cout << GREEN << Catherine.getName() << " hit points: " << Catherine.getHitPoints() << RESET << std::endl;
	Catherine.beRepaired(2);
	std::cout << GREEN << Catherine.getName() << " hit points: " << Catherine.getHitPoints() << RESET << std::endl;
	}
}