/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:36:39 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/01 14:42:53 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "color.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << GRAY_BG << this->type_ << " is created by the WrongCat's  default constructor!" <<  RESET << std::endl;
}

WrongCat::WrongCat( const WrongCat &copy ){
	*this = copy;
	std::cout << GRAY_BG << this->type_ << " is created by the WrongCat's copy constructor!" <<  RESET << std::endl;
}
	
WrongCat&  WrongCat::operator=( const WrongCat &rhs ){
	if (this != &rhs )
	{
		this->type_ = rhs.type_;
	}
	std::cout << GRAY_BG << this->type_ << " is assigned by the WrongCat's assignment operator overload!" <<  RESET << std::endl;
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << GRAY_BG << this->type_ << " is destroyed by the WrongCat's destructor!" <<  RESET << std::endl;
}

void WrongCat::makeSound( void ) const{
	std::cout << GRAY_BG << this->type_ << " makes some WrongCat sound! \"Meeeeeeoooowwww\"" <<  RESET << std::endl;
}