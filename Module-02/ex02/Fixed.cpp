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
	this->_fix_pt_number = 0;
}

Fixed::Fixed(const Fixed & old){
	*this = old; 
}

Fixed &Fixed::operator=(const Fixed &old){
	this->_fix_pt_number = old.getRawBits();
	return (*this);
}

Fixed::~Fixed(void){
}

int Fixed::getRawBits(void) const{
	return (this->_fix_pt_number);
}

void Fixed::setRawBits(int const raw){
	this->_fix_pt_number = raw;
}

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr){
	return(str << fixed_nbr.toFloat());
}

bool Fixed::operator>(const Fixed &old) const{
	return(this->toFloat() > old.toFloat());
}

bool Fixed::operator<(const Fixed &old) const{
	return(this->toFloat() < old.toFloat());
}


bool Fixed::operator>=(const Fixed &old) const{
	return(this->toFloat() >= old.toFloat());
}

bool Fixed::operator<=(const Fixed &old) const{
	return(this->toFloat() <= old.toFloat());
}

bool Fixed::operator==(const Fixed &old) const{
	return(this->toFloat() == old.toFloat());
}

bool Fixed::operator!=(const Fixed &old) const{
	return(this->toFloat() != old.toFloat());
}

Fixed Fixed::operator+(const Fixed &old) const{
	return(this->toFloat() + old.toFloat());
}

Fixed Fixed::operator-(const Fixed &old) const{
	return(this->toFloat() - old.toFloat());
}

Fixed Fixed::operator*(const Fixed &old) const{
	return(this->toFloat() * old.toFloat());
}

Fixed Fixed::operator/(const Fixed &old) const{
	return(this->toFloat() / old.toFloat());
}

Fixed &Fixed::operator++(){
	this->_fix_pt_number++;
	return(*this);
}

Fixed Fixed::operator++(int){
	Fixed copy(*this);
	operator++();
	return(copy);
}

Fixed &Fixed::operator--(){
	this->_fix_pt_number--;
	return(*this);
}

Fixed Fixed::operator--(int){
	Fixed copy(*this);
	operator--();
	return(copy);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2){
	return (num1 < num2 ? num1 : num2);
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2){
	return (num1 < num2 ? num1 : num2);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2){
	return (num1 > num2 ? num1 : num2);
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2){
	return (num1 > num2 ? num1 : num2);
}