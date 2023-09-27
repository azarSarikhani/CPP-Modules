/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:36:39 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/04 12:53:41 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "color.hpp"
#include <new>

Cat::Cat() : Animal("Cat"){
	std::cout << GRAY_BG << this->type_ << " is created by the cat's  default constructor!" <<  RESET << std::endl;
	try {
		this->brain_ = new Brain();
	}
	catch (const std::bad_alloc& error){
		std::cout << "Memory allocation failed on this computer : " << error.what() << std::endl;
	}
}

Cat::Cat( const Cat &copy ){
	*this = copy;
	std::cout << GRAY_BG << this->type_ << " is created by the cat's copy constructor!" <<  RESET << std::endl;
}
	
Cat&  Cat::operator=( const Cat &rhs ){
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
	std::cout << GRAY_BG << this->type_ << " is assigned by the cat's assignment operator overload!" <<  RESET << std::endl;
	return *this;
}

Cat::~Cat(){
	delete this->brain_;
	std::cout << GRAY_BG << this->type_ << " is destroyed by the cat's destructor!" <<  RESET << std::endl;
}

void Cat::makeSound( void ) const{
	std::cout << GRAY_BG << this->type_ << " makes some Cat sound! \"Meeeeeeoooowwww\"" <<  RESET << std::endl;
}