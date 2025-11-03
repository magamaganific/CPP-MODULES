/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:32:40 by mfornovi          #+#    #+#             */
/*   Updated: 2025/11/03 11:32:42 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type){
}

Weapon::~Weapon(void){
}

const std::string &Weapon::getType(void){
	return (this->_type);
}

void Weapon::setType(std::string type){
	this->_type = type;
}
