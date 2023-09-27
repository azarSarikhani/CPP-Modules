/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:45:56 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/29 14:11:52 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name){
	this->name_ = name;
	this->hitPoint_ = 10;
	this->energyPoint_ = 10;
	this->attackDamage_ = 0;
	std::cout << "ClapTrap " << this->name_ << " is born" << std::endl;
}

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap &copy){
	*this = copy;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs){
	this->name_ = rhs.name_;
	this->hitPoint_ = rhs.hitPoint_;
	this->energyPoint_ = rhs.energyPoint_;
	this->attackDamage_ = rhs.attackDamage_;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target){
	if (this->energyPoint_ <= 0)
	{
		std::cout << "ClapTrap " << name_ << " is out of energy!" << std::endl;
		return;
	}
	if ( this->hitPoint_ <= 0 )
	{
		std::cout << "ClapTrap " << name_ << " is out of health!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name_ << " attacks " << target << ", causing ";
	std::cout << this->attackDamage_ << " points of damage!" << std::endl;
	this->energyPoint_ -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hitPoint_ > 0){
		std::cout << "ClapTrap " << this->name_ << " takes " << amount << " damage!" << std::endl;
		this->hitPoint_ -= amount;
	}
	if (this->hitPoint_ <= 0){
		std::cout << "ClapTrap " << this->name_ << " is dead!" << std::endl;
			return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if ( this->energyPoint_ <= 0 )
	{
		std::cout << "ClapTrap " << name_ << " is out of energy!" << std::endl;
		return;
	}
	if ( this->hitPoint_ <= 0 )
	{
		std::cout << "ClapTrap " << name_ << " is out of health!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name_ << " repairs itself for " << amount << " hit points!" << std::endl;
	this->energyPoint_ -=1;
	this->hitPoint_ += amount;
}