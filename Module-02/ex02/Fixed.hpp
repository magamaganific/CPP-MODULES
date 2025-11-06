/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:17:02 by mfornovi          #+#    #+#             */
/*   Updated: 2025/11/04 12:17:06 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class	Fixed{
public:
	Fixed(void);
	Fixed(const Fixed &old);
	Fixed &operator=(const Fixed &old);
	~Fixed(void);

	Fixed(const int integer);
	Fixed(const float floater);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed &old) const;
	bool operator<(const Fixed &old) const;
	bool operator>=(const Fixed &old) const;
	bool operator<=(const Fixed &old) const;
	bool operator==(const Fixed &old) const;
	bool operator!=(const Fixed &old) const;

	Fixed operator+(const Fixed &old) const;
	Fixed operator-(const Fixed &old) const;
	Fixed operator*(const Fixed &old) const;
	Fixed operator/(const Fixed &old) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	static Fixed &min(Fixed &num1, Fixed &num2);
	static const Fixed &min(const Fixed &num1, const Fixed &num2);
	static Fixed &max(Fixed &num1, Fixed &num2);
	static const Fixed &max(const Fixed &num1, const Fixed &num2);

	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int _fix_pt_number;
	static const int _fract_bits = 8;
};

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr);
#endif
