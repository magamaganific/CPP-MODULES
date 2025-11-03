#include "Harl.hpp"

Harl::Harl(void){
}

Harl::~Harl(void){
}

void Harl::_debug(void){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-" << std::endl;
	std::cout << "ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::_info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put" << std::endl;
	std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::_warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for" << std::endl;
	std::cout << "years, whereas you started working here just last month." << std::endl << std::endl;
}

void Harl::_error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string complaint){
	void (Harl::*ptr_complain[4]) (void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string index[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4 ; i++)
	{
		if (index[i] == complaint)
		{
			(this->*ptr_complain[i])();
			break ;
		}
	}
}