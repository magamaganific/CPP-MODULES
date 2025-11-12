#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << BLUE << "[FragTrap] " << RESET << this->_name << " default constructor called" << std::endl;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &old): ClapTrap(old){
	std::cout << BLUE << "[FragTrap] " << RESET << this->_name << " copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &old){
	std::cout << BLUE << "[FragTrap] " << RESET << this->_name << " assignment operator called" << std::endl;
	if (this == &old)
		return (*this);
	_name = old.getName();
	_hit_points = old.getHitPoints();
	_energy_points = old.getEnergyPoints();
	_attack_damage = old.getAttackDamage();
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << BLUE << "[FragTrap] " << RESET << this->_name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << BLUE << "[FragTrap] " << RESET << this->_name << " requests to high-five guys" << std::endl;
}