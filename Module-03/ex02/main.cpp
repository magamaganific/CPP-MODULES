#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

#define B_G "\033[1;32m"
#define B_P "\033[1;35m"
#define B_B "\033[1;34m"

int main(void)
{
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
	{
	ScavTrap Catherine = ScavTrap("Catherine");
	
	Catherine.attack("Megalodon");
	std::cout << "	" << Catherine.getName() << GREEN << " hit points: " << Catherine.getHitPoints() << RESET << std::endl;
	std::cout << "	" << Catherine.getName() << GREEN << BLUE << " energy points: " << Catherine.getEnergyPoints() << RESET << std::endl;
	Catherine.takeDamage(5);
	std::cout << "	" << Catherine.getName() << GREEN << " hit points: " << Catherine.getHitPoints() << RESET << std::endl;
	std::cout << "	" << Catherine.getName() << BLUE << " energy points: " << Catherine.getEnergyPoints() << RESET << std::endl;
	Catherine.beRepaired(2);
	std::cout << "	" << Catherine.getName() << GREEN << " hit points: " << Catherine.getHitPoints() << RESET << std::endl;
	std::cout << "	" << Catherine.getName() << BLUE << " energy points: " << Catherine.getEnergyPoints() << RESET << std::endl;
	Catherine.guardGate();
	}
	{
	FragTrap Andrew = FragTrap("Andrew");

	Andrew.attack("Megalodon");
	std::cout << "	" << Andrew.getName() << GREEN << " hit points: " << Andrew.getHitPoints() << RESET << std::endl;
	std::cout << "	" << Andrew.getName() << GREEN << BLUE << " energy points: " << Andrew.getEnergyPoints() << RESET << std::endl;
	Andrew.takeDamage(5);
	std::cout << "	" << Andrew.getName() << GREEN << " hit points: " << Andrew.getHitPoints() << RESET << std::endl;
	std::cout << "	" << Andrew.getName() << BLUE << " energy points: " << Andrew.getEnergyPoints() << RESET << std::endl;
	Andrew.beRepaired(2);
	std::cout << "	" << Andrew.getName() << GREEN << " hit points: " << Andrew.getHitPoints() << RESET << std::endl;
	std::cout << "	" << Andrew.getName() << BLUE << " energy points: " << Andrew.getEnergyPoints() << RESET << std::endl;
	Andrew.highFivesGuys();
	}
}