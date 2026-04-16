/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:23:20 by pcaplat           #+#    #+#             */
/*   Updated: 2026/04/16 17:29:52 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class	Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits;

public:
	Fixed (void);
	Fixed (const Fixed &);
	~Fixed (void);
	Fixed &operator= (const Fixed &);

	int		getRawBits(void) const;
	void	setRawBits(int const);
};
