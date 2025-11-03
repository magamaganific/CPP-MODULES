#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl{
public:
	Harl(void);
	~Harl(void);

	void complain(std::string complaint);
private:
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
};

#endif