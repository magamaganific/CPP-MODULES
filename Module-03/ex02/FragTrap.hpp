#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
public:
	explicit FragTrap(std::string name);
	FragTrap(const FragTrap &old);
	FragTrap &operator=(const FragTrap &old);
	~FragTrap (void);

	void highFivesGuys(void);
};

#endif