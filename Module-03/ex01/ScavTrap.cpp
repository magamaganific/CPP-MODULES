#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << this->_name << " default constructor called" << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &old): ClapTrap(old){
	std::cout << "ScavTrap " << this->_name << " copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &old){
	std::cout << "ScavTrap " << this->_name << " assignment operator called" << std::endl;
	if (this == &old)
		return (*this);
	_name = old.getName();
	_hit_points = old.getHitPoints();
	_energy_points = old.getEnergyPoints();
	_attack_damage = old.getAttackDamage();
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

void ScavTrap::guardGate(void){
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper Mode" << std::endl;
}