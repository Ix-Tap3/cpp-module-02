/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:47:27 by pcaplat           #+#    #+#             */
/*   Updated: 2026/04/17 16:22:00 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cmath>

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed (void)
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed (const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed (int const n)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = n << _fractionalBits;
}

Fixed::Fixed (float const n)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(n * (1 << _fractionalBits));
}

// Destructor
Fixed::~Fixed (void)
{
	std::cout << "Destructor called" << std::endl;
}

// Operator overloading
Fixed	&Fixed::operator= (const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

std::ostream	&operator<< (std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat();
	return (out);
}

bool	Fixed::operator< (Fixed const &other) {return (this->_rawBits < other._rawBits);}
bool	Fixed::operator> (Fixed const &other) {return (this->_rawBits > other._rawBits);}
bool	Fixed::operator<= (Fixed const &other) {return (this->_rawBits <= other._rawBits);}
bool	Fixed::operator>= (Fixed const &other) {return (this->_rawBits >= other._rawBits);}
bool	Fixed::operator== (Fixed const &other) {return (this->_rawBits == other._rawBits);}
bool	Fixed::operator!= (Fixed const &other) {return (this->_rawBits != other._rawBits);}
int		Fixed::operator+ (Fixed const &other)
{
	return ((this->toInt() + other.toInt()) << _fractionalBits);
}
int		Fixed::operator- (Fixed const &other) {return (this->_rawBits - other._rawBits);}
int		Fixed::operator* (Fixed const &other) {return (this->_rawBits * other._rawBits);}
int		Fixed::operator/ (Fixed const &other) {return (this->_rawBits / other._rawBits);}

// member functions
float	Fixed::toFloat(void) const {return (static_cast<float>(_rawBits) / (1 << _fractionalBits));}
int		Fixed::toInt(void) const {return (_rawBits >> _fractionalBits);}

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
