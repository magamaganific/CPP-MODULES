/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:31:50 by mfornovi          #+#    #+#             */
/*   Updated: 2025/11/03 11:31:55 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(&weapon){
}

HumanA::~HumanA(void){
}

void HumanA::attack(void){
	std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon){
	this->_weapon = &weapon;
}
