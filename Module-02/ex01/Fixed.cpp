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

static float ft_pow(float base, int exp){
	float res;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	res = base;
	while(--exp)
		res *= base;
	return (res);
}

Fixed::Fixed(const int integer): _fix_pt_number(integer * ft_pow(2, this->_fract_bits)){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floater): _fix_pt_number(floater * ft_pow(2, this->_fract_bits)){
	std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt(void) const{
	return(this->_fix_pt_number * ft_pow(2, -this->_fract_bits));
}

float Fixed::toFloat(void) const{
	return(this->_fix_pt_number * ft_pow(2, -this->_fract_bits));
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
