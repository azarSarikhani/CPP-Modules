/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarsarikhani <azarsarikhani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:56:42 by azarsarikha       #+#    #+#             */
/*   Updated: 2023/08/23 13:31:18 by azarsarikha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0){
    std::cout << "Default constructor called" << std::endl;
    //this->_fixedPointValue = 0;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPointValue = raw;
}
