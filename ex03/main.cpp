/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:30:01 by pcaplat           #+#    #+#             */
/*   Updated: 2026/04/20 12:32:21 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <ostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

static std::string	displayBool(bool value)
{
	if (value == true)
		return ("yes");
	else
		return ("no");
}

int	main(void)
{
	Point	a;
	Point	b(10, 30);
	Point	c(20, 0);
	Point	p1(10, 30);
	Point	p2(30, 15);

	std::cout << a << std::endl;
	std::cout << "A: " << a << ", B: " << b << ", C: " << c << std::endl;
	std::cout << "Is p1" << p1 << " lies inside the ABC triangle ? " << displayBool(bsp(a, b, c, p1)) << std::endl;
	std::cout << "Is p2" << p2 << " lies inside the ABC triangle ? " << displayBool(bsp(a, b, c, p2)) << std::endl;
	return (0);
}
