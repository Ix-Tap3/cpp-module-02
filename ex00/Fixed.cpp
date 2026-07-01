/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:47:27 by pcaplat           #+#    #+#             */
/*   Updated: 2026/07/01 08:44:22 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed (void)
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed (const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

Fixed::~Fixed (void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator= (const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const n)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = n;
}
