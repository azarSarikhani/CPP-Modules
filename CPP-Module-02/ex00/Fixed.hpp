/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:31:47 by azarsarikha       #+#    #+#             */
/*   Updated: 2023/09/07 13:42:34 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int                 _fixedPointValue;
		static const int    _fractionalBits = 8;

	public:
	// Constructors
		Fixed();
		Fixed(const Fixed& copy);

	// Deconstructors
		~Fixed();

	// Overloaded Operators
		Fixed &operator=(const Fixed &src);

	// Public Methods

	// Getter
		int getRawBits(void)const;
	// Setter
		void setRawBits(int const raw);
};

#endif 