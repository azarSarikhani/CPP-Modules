/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:25:19 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/04 13:33:08 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "color.hpp"

Animal::Animal() : type_("Default Animal"){
	std::cout << YELLOW_BG << this->type_ << " is created by the Animal's default constructor!" <<  RESET << std::endl;
}

Animal::Animal( std::string type ) : type_(type){
	std::cout << YELLOW_BG << this->type_ << " is created by the Animal's constructor" <<  RESET << std::endl;
}

Animal::Animal( const Animal &copy ){
	*this = copy;
	std::cout << YELLOW_BG << this->type_ << " is created by the Animal's copy constructor!" <<  RESET << std::endl;
}

Animal& Animal::operator=( const Animal& rhs){
	if (this != &rhs )
	{
		this->type_ = rhs.type_;
	}
	std::cout << YELLOW_BG << this->type_ << " is assigned by the Animal's assignment operator overload!" <<  RESET << std::endl;
	return *this;
}

Animal::~Animal(){
	std::cout << YELLOW_BG << this->type_ << " is destroyed by the Animal's destructor!" <<  RESET << std::endl;
}

void Animal::makeSound( void ) const{
	std::cout << YELLOW_BG << this->type_ << " makes  appropriate "  << this->type_ << " sound!" <<  RESET << std::endl;
}

std::string Animal::getType( void ) const{
	return this->type_;
}