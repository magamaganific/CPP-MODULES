/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:39:40 by mfornovi          #+#    #+#             */
/*   Updated: 2025/11/03 12:39:42 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int replace(char **av, std::string str)
{
	std::ofstream outfile;
	int pos;

	outfile.open((std::string(av[1]) + ".replace").c_str());
	if(outfile.fail())
		return(1);
	for(int i = 0; i < (int)str.size() - 1; i++)
	{
		pos = str.find(av[2], i);
		if (pos != -1 && pos == i)
		{
			outfile << av[3];
			i += std::string(av[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return(0);
}


int main (int ac, char **av)
{
	char c;
	std::ifstream infile;
	std::string str;

	if (ac != 4)
		return(1);
	if(!av[1][0] || !av[2][0] || !av[3][0])
	{
		std::cout << "invalid input" << std::endl;
		return (1);
	}
	infile.open(av[1]);
	if(infile.fail())
		return(1);
	while(!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	infile.close();
	return(replace(av, str));
}
