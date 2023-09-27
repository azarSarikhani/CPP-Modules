/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:36:39 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/01 14:00:08 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "color.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << GRAY_BG << this->type_ << " is created by the cat's  default constructor!" <<  RESET << std::endl;
}

Cat::Cat( const Cat &copy ){
	*this = copy;
	std::cout << GRAY_BG << this->type_ << " is created by the cat's copy constructor!" <<  RESET << std::endl;
}
	
Cat&  Cat::operator=( const Cat &rhs ){
	if (this != &rhs )
	{
		this->type_ = rhs.type_;
	}
	std::cout << GRAY_BG << this->type_ << " is assigned by the cat's assignment operator overload!" <<  RESET << std::endl;
	return *this;
}

Cat::~Cat(){
	std::cout << GRAY_BG << this->type_ << " is destroyed by the cat's destructor!" <<  RESET << std::endl;
}

void Cat::makeSound( void ) const{
	std::cout << GRAY_BG << this->type_ << " makes some Cat sound! \"Meeeeeeoooowwww\"" <<  RESET << std::endl;
}