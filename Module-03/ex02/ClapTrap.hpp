#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <iostream>

#define GREEN "\033[0;32m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[m"

class ClapTrap{
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &old);
	ClapTrap &operator=(const ClapTrap &old);
	~ClapTrap(void);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName(void) const;
	unsigned int getHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getAttackDamage(void) const;
protected:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;
};
#endif