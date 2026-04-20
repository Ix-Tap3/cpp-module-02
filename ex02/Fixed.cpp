/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:47:27 by pcaplat           #+#    #+#             */
/*   Updated: 2026/04/20 09:49:32 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cmath>

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed (void) : _rawBits(0) {}
Fixed::Fixed (float const n) : _rawBits(roundf(n * (1 << _fractionalBits))) {}
Fixed::Fixed (int const n) : _rawBits(n << _fractionalBits) {}
Fixed::~Fixed (void) {}
Fixed::Fixed (const Fixed &other)
{
	if (*this != other)
		*this = other;
}

// Operator overloading
Fixed	&Fixed::operator= (const Fixed &other)
{
	// std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

std::ostream	&operator<< (std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat();
	return (out);
}

bool	Fixed::operator< (Fixed const &other) const {return (this->_rawBits < other._rawBits);}
bool	Fixed::operator> (Fixed const &other) const {return (this->_rawBits > other._rawBits);}
bool	Fixed::operator<= (Fixed const &other) const {return (this->_rawBits <= other._rawBits);}
bool	Fixed::operator>= (Fixed const &other) const {return (this->_rawBits >= other._rawBits);}
bool	Fixed::operator== (Fixed const &other) const {return (this->_rawBits == other._rawBits);}
bool	Fixed::operator!= (Fixed const &other) const {return (this->_rawBits != other._rawBits);}


/* ************************************************************************* */
/*                                                                           */
/*                     Arithmetic operator overloading                       */
/*                                                                           */
/* ************************************************************************* */
Fixed	Fixed::operator+ (Fixed const &other)
{
	Fixed	result;

	result.setRawBits(this->_rawBits + other._rawBits);
	return (result);
}
Fixed	Fixed::operator- (Fixed const &other)
{
	Fixed	result;

	result.setRawBits(this->_rawBits - other._rawBits);
	return (result);
}
Fixed	Fixed::operator* (Fixed const &other)
{
	float	result;

	result = this->toFloat() * other.toFloat();
	return (result);
}
Fixed	Fixed::operator/ (Fixed const &other)
{
	float	result;

	result = this->toFloat() / other.toFloat();
	return (result);
}
Fixed	&Fixed::operator++ (void)
{
	this->_rawBits += 1;
	return (*this);
}
Fixed	Fixed::operator++ (int)
{
	Fixed	tmp(*this);

	this->_rawBits += 1;
	return (tmp);
}
Fixed	&Fixed::operator-- (void)
{
	this->_rawBits -= 1;
	return (*this);
}
Fixed	Fixed::operator-- (int)
{
	Fixed	tmp(*this);

	this->_rawBits -= 1;
	return (tmp);
}

// member functions
float	Fixed::toFloat(void) const {return (static_cast<float>(_rawBits) / (1 << _fractionalBits));}
int		Fixed::toInt(void) const {return (_rawBits >> _fractionalBits);}

int		Fixed::getRawBits(void) const 
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const n)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_rawBits = n;
}
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}
Fixed const	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
Fixed const	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
