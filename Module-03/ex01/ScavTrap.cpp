#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << PURPLE << "[ScavTrap] " << RESET << this->_name << " default constructor called" << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &old): ClapTrap(old){
	std::cout << PURPLE << "[ScavTrap] " << RESET << this->_name << " copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &old){
	std::cout << PURPLE << "[ScavTrap] " << RESET << this->_name << " assignment operator called" << std::endl;
	if (this == &old)
		return (*this);
	_name = old.getName();
	_hit_points = old.getHitPoints();
	_energy_points = old.getEnergyPoints();
	_attack_damage = old.getAttackDamage();
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << PURPLE << "[ScavTrap] " << RESET << this->_name << " destructor called" << std::endl;
}

void ScavTrap::guardGate(void){
	std::cout << PURPLE << "[ScavTrap] " << RESET << this->_name << " is now in Gate Keeper Mode" << std::endl;
}

void ScavTrap::attack(std::string target){
std::cout << PURPLE << "[ScavTrap] " << RESET << this->_name << " attacks " << target <<
	" causing " << BLUE << this->getAttackDamage() << RESET << " points of damage!" << std::endl;
}