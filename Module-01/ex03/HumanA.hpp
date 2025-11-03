/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:32:01 by mfornovi          #+#    #+#             */
/*   Updated: 2025/11/03 11:32:03 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
#include "Weapon.hpp"
#include <iostream>

class HumanA{
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void attack(void);
	void setWeapon(Weapon weapon);
private:
	std::string _name;
	Weapon *_weapon;
};

#endif
