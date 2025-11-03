/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:32:48 by mfornovi          #+#    #+#             */
/*   Updated: 2025/11/03 11:32:50 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon{
public:
	Weapon(std::string type);
	~Weapon(void);

	const std::string& getType(void);
	void setType(std::string type);
private:
	std::string _type;
};

#endif

