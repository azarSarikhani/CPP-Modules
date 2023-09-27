/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:08:20 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/30 12:47:40 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoint_ = 100;
	this->energyPoint_ = 100;
	this->attackDamage_ = 30;
	std::cout << "FragTrap " << this->name_ << " is constructed" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << this->name_ << " destructor called" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("Default FragTrap"){
	this->name_ = "Default FragTrap";
	this->hitPoint_ = 100;
	this->energyPoint_ = 100;
	this->attackDamage_ = 30;
	std::cout << "FragTrap " << this->name_ << " default constructor called" << std::endl;
	
}

FragTrap::FragTrap( FragTrap &copy) : ClapTrap(copy.name_){
	*this = copy;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs){
	this->name_ = rhs.name_;
	this->hitPoint_ = rhs.hitPoint_;
	this->energyPoint_ = rhs.energyPoint_;
	this->attackDamage_ = rhs.attackDamage_;
	return *this;
}

void	FragTrap::highFive( void ){
		if (this->energyPoint_ <= 0)
	{
		std::cout << "FragTrap " << name_ << " is out of energy!" << std::endl;
		return;
	}
	if ( this->hitPoint_ <= 0 )
	{
		std::cout << "FragTrap " << name_ << " is out of health!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name_ << " high fives Bart Simpson." << std::endl;
}