/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:09:41 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/30 12:49:33 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap:: ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoint_ = 100;
	this->energyPoint_ = 50;
	this->attackDamage_ = 20;
	std::cout << "ScavTrap " << this->name_ << " is constructed" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap("Default ScavTrap"){
	this->name_ = "Default ScavTrap";
	this->hitPoint_ = 100;
	this->energyPoint_ = 50;
	this->attackDamage_ = 20;
	std::cout << "ScavTrap " << this->name_ << " default constructor called" << std::endl;
	this->name_ = "Default ScavTrap";
}

ScavTrap::ScavTrap( ScavTrap &copy) : ClapTrap(copy.name_){
	*this = copy;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs){
	this->name_ = rhs.name_;
	this->hitPoint_ = rhs.hitPoint_;
	this->energyPoint_ = rhs.energyPoint_;
	this->attackDamage_ = rhs.attackDamage_;
	return *this;
}

ScavTrap::~ ScavTrap(){
	
	std::cout << "ScavTrap " << this->name_ << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target){
	if (this->energyPoint_ <= 0)
	{
		std::cout << "ScavTrap " << name_ << " is out of energy!" << std::endl;
		return;
	}
	if ( this->hitPoint_ <= 0 )
	{
		std::cout << "ScavTrap " << name_ << " is out of health!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name_ << " attacks " << target << ", causing ";
	std::cout << this->attackDamage_ << " points of damage!" << std::endl;
	this->energyPoint_ -= 1;
}

void	ScavTrap::gaurdGate(){
	std::cout << "ScavTrap " << this->name_ << " is now in Gate keeper mode" << std::endl;
}