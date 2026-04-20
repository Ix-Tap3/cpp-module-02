/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:41:41 by pcaplat           #+#    #+#             */
/*   Updated: 2026/04/20 14:19:20 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	ft_abs(float nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

static float	area(Point const a, Point const b, Point const c)
{
	float	result;

	result = ft_abs(((b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY()))) / 2;
	return (result);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	Area;
	float	Area1;
	float	Area2;
	float	Area3;

	if (point == a || point == b || point == c)
		return (false);
	Area = area(a, b, c);
	Area1 = area(point, a, b);
	Area2 = area(point, b, c);
	Area3 = area(point, a, c);
	if (Area1 == 0 || Area2 == 0 || Area3 == 0)
		return (false);
	if (Area == Area1 + Area2 + Area3)
		return (true);
	return (false);
}
