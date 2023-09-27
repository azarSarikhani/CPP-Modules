/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:36:39 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/01 14:00:12 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "color.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << BROWN << this->type_ << " is created by the dog's default constructor!" <<  RESET << std::endl;
}

Dog::Dog( const Dog &copy ){
	*this = copy;
	std::cout << BROWN << this->type_ << " is created by the dog's copy constructor!" <<  RESET << std::endl;
}
	
Dog&  Dog::operator=( const Dog &rhs ){
	if (this != &rhs )
	{
		this->type_ = rhs.type_;
	}
	std::cout << BROWN << this->type_ << " is assigned by the dog's assignment operator overload!" <<  RESET << std::endl;
	return *this;
}

Dog::~Dog(){
	std::cout << BROWN << this->type_ << " is destroyed by the dog's destructor!" <<  RESET << std::endl;
}

void Dog::makeSound( void ) const{
	std::cout << BROWN << this->type_ << " makes a cute Dog sound! \"Barf Barf\"" <<  RESET << std::endl;
}