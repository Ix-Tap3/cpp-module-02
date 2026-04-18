/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:23:20 by pcaplat           #+#    #+#             */
/*   Updated: 2026/04/18 17:37:37 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>

class	Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits;

public:
	Fixed (void);
	Fixed (int const);
	Fixed (float const);
	Fixed (Fixed const &);
	~Fixed (void);

	Fixed	&operator= (const Fixed &);
	Fixed	operator+ (const Fixed &);
	Fixed	operator- (const Fixed &);
	Fixed	operator* (const Fixed &);
	Fixed	operator/ (const Fixed &);
	bool	operator< (const Fixed &);
	bool	operator> (const Fixed &);
	bool	operator<= (const Fixed &);
	bool	operator>= (const Fixed &);
	bool	operator== (const Fixed &);
	bool	operator!= (const Fixed &);

	void	setRawBits(int const);
	int		getRawBits(void) const;
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<< (std::ostream &, const Fixed &);
