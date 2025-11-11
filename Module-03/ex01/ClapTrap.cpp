#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):
		_name(name), _hit_points(10), _energy_points(10), _attack_damage(0){
	std::cout << "ClapTrap constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &old):
		_hit_points(), _energy_points(), _attack_damage(){
	std::cout << "Copy constructor called" << std::endl;
	*this = old;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &old){

}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap destroyed" << std::endl;
}

std::string ClapTrap::getName(void) const{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints(void) const{
	return (this->_hit_points);
}

unsigned int ClapTrap::getEnergyPoints(void) const{
	return (this->_energy_points);
}

unsigned int ClapTrap::getAttackDamage(void) const{
	return (this->_attack_damage);
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

