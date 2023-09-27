/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:25:19 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/01 14:00:18 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "color.hpp"

WrongAnimal::WrongAnimal() : type_("Default WrongAnimal"){
	std::cout << YELLOW_BG << this->type_ << " is created by the WrongAnimal's default constructor!" <<  RESET << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type_(type){
	std::cout << YELLOW_BG << this->type_ << " is created by the WrongAnimal's constructor" <<  RESET << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &copy ){
	*this = copy;
	std::cout << YELLOW_BG << this->type_ << " is created by the WrongAnimal's copy constructor!" <<  RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& rhs){
	if (this != &rhs )
	{
		this->type_ = rhs.type_;
	}
	std::cout << YELLOW_BG << this->type_ << " is assigned by the WrongAnimal's assignment operator overload!" <<  RESET << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << YELLOW_BG << this->type_ << " is destroyed by the WrongAnimal's destructor!" <<  RESET << std::endl;
}

void WrongAnimal::makeSound( void ) const{
	std::cout << YELLOW_BG << this->type_ << " makes some Wronganimal sound!" <<  RESET << std::endl;
}

std::string WrongAnimal::getType( void ) const{
	return this->type_;
}