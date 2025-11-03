/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:32:07 by mfornovi          #+#    #+#             */
/*   Updated: 2025/11/03 11:32:11 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _name(name), _weapon(NULL){
}

HumanB::~HumanB(void){
}

void HumanB::attack(void){
	std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}
