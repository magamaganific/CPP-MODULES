#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &old);
	ScavTrap &operator=(const ScavTrap &old);
	~ScavTrap (void);

	void guardGate(void);
	void attack(const std::string target);
};

#endif