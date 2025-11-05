/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:16:50 by mfornovi          #+#    #+#             */
/*   Updated: 2025/11/04 12:16:54 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
	this->_fix_pt_number = 0;
}

Fixed::Fixed(const Fixed & old){
	std::cout << "Copy constructor called" << std::endl;
	*this = old; 
}

Fixed &Fixed::operator=(const Fixed &old){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fix_pt_number = old.getRawBits();
	return (*this);
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << "GetRawBits member fuction called" << std::endl;
	return (this->_fix_pt_number);
}

void Fixed::setRawBits(int const raw){
	std::cout << "SetRawBits member fuction called" << std::endl;
	this->_fix_pt_number = raw;
}