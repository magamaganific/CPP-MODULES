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

Fixed::Fixed(const int integer): _fix_pt_number(integer * int(1 << _fract_bits) + (integer >= 0 ? 0.5 : -0.5)){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floater): _fix_pt_number(floater * int(1 << _fract_bits) + (floater >= 0 ? 0.5 : -0.5)){
	std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt(void) const{
	return(int(_fix_pt_number) / int(1 << _fract_bits));
}

float Fixed::toFloat(void) const{
	return(float(_fix_pt_number) / float(1 << _fract_bits));
}


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

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr){
	return(str << fixed_nbr.toFloat());
}
