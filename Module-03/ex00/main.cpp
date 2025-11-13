#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{

	ClapTrap Marcus =  ClapTrap("Marcus");

	std::cout << "	" << Marcus.getName() << BLUE << " energy points: " << Marcus.getEnergyPoints() << RESET << std::endl;
	Marcus.attack("Megalodon");
	std::cout << "	" << Marcus.getName() << GREEN << " hit points: " << Marcus.getHitPoints() << RESET << std::endl;
	std::cout << "	" << Marcus.getName() << BLUE << " energy points: " << Marcus.getEnergyPoints() << RESET << std::endl;
	Marcus.takeDamage(5);
	std::cout << "	" << Marcus.getName() << GREEN << " hit points: " << Marcus.getHitPoints() << RESET << std::endl;
	std::cout << "	" << Marcus.getName() << BLUE << " energy points: " << Marcus.getEnergyPoints() << RESET << std::endl;
	Marcus.beRepaired(2);
	std::cout << "	" << Marcus.getName() << GREEN << " hit points: " << Marcus.getHitPoints() << RESET << std::endl;
	std::cout << "	" << Marcus.getName() << BLUE << " energy points: " << Marcus.getEnergyPoints() << RESET << std::endl;
}