/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:30:01 by pcaplat           #+#    #+#             */
/*   Updated: 2026/04/17 16:14:56 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>

int	main(void)
{
	Fixed	a(42.42f);
	Fixed	b(10);
	Fixed	c;
	
	c = a - b;
	std::cout << a << " + " << b << " = " << c << std::endl;
	std::cout << c << std::endl;
	return (0);
}
