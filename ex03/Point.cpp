/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:25:32 by pcaplat           #+#    #+#             */
/*   Updated: 2026/04/20 12:38:11 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <ostream>

Point::Point (void) : _x(0), _y(0) {}
Point::Point (float const x, float const y) : _x(x), _y(y) {}
Point::Point (Point const &other)
{
	if (this != &other)
		*this = other;
}
Point::~Point (void) {}

Point	&Point::operator= (Point const &other)
{
	Fixed	tmp;

	tmp = other._x.getRawBits();
	if (this != &other)
	{
		const_cast<Fixed &>(this->_x).setRawBits(other._x.getRawBits());
		const_cast<Fixed &>(this->_y).setRawBits(other._y.getRawBits());
	}
	return (*this);
}

bool	Point::operator== (Point const &other) const
{
	if (this->getX() == other.getX() && this->getY() == other.getY())
		return (true);
	return (false);
}

float	Point::getX(void) const {return (_x.toFloat());}
float	Point::getY(void) const {return (_y.toFloat());}

std::ostream	&operator<< (std::ostream &out, Point &obj)
{
	out << "(" << obj.getX() << ", " << obj.getY() << ")";
	return (out);
}
