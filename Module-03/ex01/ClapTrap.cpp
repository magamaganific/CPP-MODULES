#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):
		_name(name), _hit_points(10), _energy_points(10), _attack_damage(0){
	std::cout << "ClapTrap constructed" << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target){
	std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< " causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << this->_name << " has recieved "
		<< amount << " points of damage!" << std::endl;
	this->_hit_points -= amount;
	this->_hit_points = 0;
}

void ClapTrap::beRepaired(unsigned int amount){
	this->_hit_points += amount;
	this->_energy_points -= 1;
	std::cout << "ClapTrap " << this->_name << " has repaired itself -"
		<< amount << " points of damage!" << std::endl;
}

