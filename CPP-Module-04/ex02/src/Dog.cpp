/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:36:39 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/04 12:53:59 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "color.hpp"
#include <new>

Dog::Dog() : Animal("Dog"){
	std::cout << BROWN << this->type_ << " is created by the dog's default constructor!" <<  RESET << std::endl;
	try {
		this->brain_ = new Brain();
	}
	catch (const std::bad_alloc& error){
		std::cout << "Memory allocation failed on this computer : " << error.what() << std::endl;
	}
}

Dog::Dog( const Dog &copy ){
	std::cout << BROWN << this->type_ << " is created by the dog's copy constructor!" <<  RESET << std::endl;
	*this = copy;
}
	
Dog&  Dog::operator=( const Dog &rhs ){
	if (this != &rhs )
	{
		try {
		this->brain_ = new Brain();
		}
		catch (const std::bad_alloc& error){
			std::cout << "Memory allocation failed on this computer : " << error.what() << std::endl;
		}
		this->type_ = rhs.type_;
	}
	std::cout << BROWN << this->type_ << " is assigned by the dog's assignment operator overload!" <<  RESET << std::endl;
	return *this;
}

Dog::~Dog(){
	delete this->brain_;
	std::cout << BROWN << this->type_ << " is destroyed by the dog's destructor!" <<  RESET << std::endl;
}

void Dog::makeSound( void ) const{
	std::cout << BROWN << this->type_ << " makes a cute Dog sound! \"Barf Barf\"" <<  RESET << std::endl;
}