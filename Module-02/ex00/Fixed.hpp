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
	Fixed(const Fixed &other)
	~Fixed(void);
private:
	int _fix_pt_number;
	static const int fract_bits = 8;
}


#endif
