/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:29:34 by mfornovi          #+#    #+#             */
/*   Updated: 2025/11/03 11:29:35 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	int size = 20;
	Zombie *horde = zombieHorde(20, "Daniel");

	for (int i = 0; i < size; i++)
		horde[i].announce();
	return(0);
}
