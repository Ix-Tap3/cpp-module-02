/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:20:32 by pcaplat           #+#    #+#             */
/*   Updated: 2026/04/20 12:38:04 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <ostream>

class	Point
{
private:
	Fixed const	_x;
	Fixed const	_y;

public:
	Point	(void);
	Point	(float const, float const);
	Point	(Point const &);
	~Point	(void);

	Point	&operator= (Point const &);
	bool	operator== (Point const &) const;

	float	getX(void) const;
	float	getY(void) const;
};

std::ostream	&operator<< (std::ostream &, Point &);
