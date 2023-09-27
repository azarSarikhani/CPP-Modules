/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:31:47 by azarsarikha       #+#    #+#             */
/*   Updated: 2023/08/25 13:23:03 by asarikha         ###   ########.fr       */
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
		
	//Comparation Operators
		bool	operator>(Fixed const &src) const;
		bool	operator<(Fixed const &src) const;
		bool	operator>=(Fixed const &src) const;
		bool	operator<=(Fixed const &src) const;
		bool	operator==(Fixed const &src) const;
		bool	operator!=(Fixed const &src) const;
		
	//Aritmethic Operators
		Fixed	operator+(Fixed const &src) const;
		Fixed	operator-(Fixed const &src) const;
		Fixed	operator*(Fixed const &src) const;
		Fixed	operator/(Fixed const &src) const;

	//Increment/Decrement Operator	
		Fixed	&operator++(void);		  //prefix
		Fixed	operator++(int);		  //postfix
		Fixed	&operator--(void);		  //prefix
		Fixed	operator--(int); 	      //postfix

	// Public Methods
		float   toFloat( void ) const;
		int     toInt( void ) const;
	// Getter
		int 	getRawBits(void)const;
	// Setter
		void 	setRawBits(int const raw);
	//static function members
		static	Fixed& min ( Fixed &a, Fixed &b);
		static	Fixed& max ( Fixed &a, Fixed &b);
		static	const Fixed& min ( Fixed const &a, Fixed const &b);
		static	const Fixed& max ( Fixed const &a, Fixed const &b);
};
std::ostream & operator<<( std::ostream & outputStream, Fixed const & instance );
#endif 