/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:56:42 by azarsarikha       #+#    #+#             */
/*   Updated: 2023/08/24 15:14:53 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0){
    std::cout << "Default constructor called" << std::endl;
    //this->_fixedPointValue = 0;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const int num ) : _fixedPointValue( num << _fractionalBits ) {
    std::cout << "Int constructor called" << std::endl;
    //this->_fixedPointValue = num << this->_fractionalBits;
}

Fixed::Fixed( const float num ) /* : _fixedPointValue( std::roundf( num * ( 1 << _fractionalBits ) ) )*/ {
    std::cout << "Float constructor called" << std::endl;
    
    //this->_fixedPointValue = roundf(num * (1 << this->_fractionalBits));
    
    int power = _ft_pow(2, this->_fractionalBits);
	this->_fixedPointValue = roundf(num * power);
}

Fixed::Fixed(const Fixed& copy){
    std::cout << "Copy constructor called" << std::endl;
    //this->setRawBits(copy.getRawBits());
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &src){
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointValue = src.getRawBits();

	return *this;
}

int Fixed::getRawBits( void ) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPointValue = raw;
}

float   Fixed::toFloat( void ) const {
    //return static_cast<float>( this->getRawBits() ) / ( 1 << _fractionalBits );
    //return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));

    int		power = this->_ft_pow(2, this->_fractionalBits);
	float	result = (float)this->_fixedPointValue / power;

	return (result);
}

int     Fixed::toInt( void ) const {
    return this->_fixedPointValue >> _fractionalBits;
    //return (this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream & operator<<( std::ostream & outputStream, Fixed const & instance ) {
    outputStream << instance.toFloat();
    return outputStream;
}

int     Fixed::_ft_pow(int  value, int power) const{
    int i = 0;
    int result;

    result = 1;
    while (i < power){
        result *= value;
        i++;
    }
    return (result);
}