#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	explicit ScavTrap(std::string name);
};

#endif