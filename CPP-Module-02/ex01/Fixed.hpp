/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:31:47 by azarsarikha       #+#    #+#             */
/*   Updated: 2023/08/24 15:01:38 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int                 _fixedPointValue;
		static const int    _fractionalBits;
		int     _ft_pow(int  value, int power) const;

	public:
	// Constructors
		Fixed( void );
		Fixed( const int num );
		Fixed( const float num );
		Fixed(const Fixed& copy);

	// Deconstructors
		~Fixed();

	// Overloaded Operators
		Fixed &operator=(const Fixed &src);

	// Public Methods
		float   toFloat( void ) const;
		int     toInt( void ) const;
	// Getter
		int getRawBits(void)const;
	// Setter
		void setRawBits(int const raw);
};
std::ostream & operator<<( std::ostream & outputStream, Fixed const & instance );
#endif 