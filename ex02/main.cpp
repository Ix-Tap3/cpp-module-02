/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:30:01 by pcaplat           #+#    #+#             */
/*   Updated: 2026/04/20 09:50:58 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>

static std::string	displayBool(bool value)
{
	if (value == true)
		return ("true");
	else
		return ("false");
}

int	main(void)
{
	{
		Fixed	a(42.42f);
		Fixed	b = 10;
		Fixed	c;
		bool	result;

		c = b;
		result = a < b;
		std::cout << "Overloadead Logical operators" << std::endl;
		std::cout << std::endl;
		std::cout << a << " > " << b << ": " << displayBool(a > b) << std::endl;
		std::cout << a << " < " << b << ": " << displayBool(result) << std::endl;
		std::cout << a << " >= " << b << ": " << displayBool(a >= b) << std::endl;
		std::cout << c << " <= " << b << ": " << displayBool(c <= b) << std::endl;
		std::cout << "So, " << c << " == " << b << ": " << displayBool(c == b) << std::endl;
		std::cout << "And, " << c << " != " << b << ": " << displayBool(c != b) << std::endl;
		std::cout << std::endl;
	}
	{
		Fixed	a(42.42f);
		Fixed	b(10);
		Fixed	c;
		Fixed	d = 2;

		std::cout << std::endl;
		std::cout << "Overloadead arithmetic operators tests\n" << std::endl;
		c = a + b;
		std::cout << a << " + " << b << " = " << c << std::endl;
		std::cout << b << " * " << d << " = " << b * d << std::endl;
		std::cout << a << " / " << d << " = " << a / d << std::endl;
		std::cout << a << " - " << c << " = " << a - c << std::endl;
		std::cout << std::endl;

	}
	{
		Fixed	e(1);

		std::cout << std::endl;
		std::cout << "Increment and Decrement operators tests\n" << std::endl;
		std::cout << "e: " << e << ", ++e = " << ++e << std::endl;
		std::cout << "e: " << e << ", e++ = " << e++ << std::endl;
		std::cout << "e after post-increment: " << e << std::endl;
		std::cout << "e: " << e << ", --e = " << --e << std::endl;
		std::cout << "e: " << e << ", e-- = " << e-- << std::endl;
		std::cout << "e after post-decrement: " << e << std::endl;
		std::cout << std::endl;
	}
	{
		Fixed		a(42);
		Fixed		b(21);
		Fixed const	c(165);
		Fixed const d(164);

		std::cout << std::endl;
		std::cout << "Min and Max tests\n" << std::endl;
		std::cout << "a: " << a << ", b: " << b << ", min: " << Fixed::min(a, b) << std::endl;
		std::cout << "c: " << c << ", d: " << d << ", min: " << Fixed::min(c, d) << std::endl;
		std::cout << "a: " << a << ", b: " << b << ", max: " << Fixed::max(a, b) << std::endl;
		std::cout << "c: " << c << ", d: " << d << ", max: " << Fixed::max(c, d) << std::endl;
	}
	
	return (0);
}
