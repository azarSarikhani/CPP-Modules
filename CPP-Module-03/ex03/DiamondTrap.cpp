/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:21:04 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/26 15:57:14 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap:: DiamondTrap(std::string name ) : ClapTrap( name ), FragTrap ( name ), ScavTrap( name )
{
	this->name_ = name;
	this->ClapTrap::name_ = name + "_clap_name";
	this->hitPoint_ = 100; // = Scavtrap::hitpoit;
	this->energyPoint_ = 50;
	this->attackDamage_ = 30;
	std::cout << "DiamondTrap " << this->name_ << " is constructed" << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap("Default DiamondTrap"), FragTrap ("Default DiamondTrap"), ScavTrap("Default DiamondTrap"){
	this->name_ = "Default DiamondTrap";
	this->hitPoint_ = 100;
	this->energyPoint_ = 50;
	this->attackDamage_ = 30;
	std::cout << "DiamondTrap " << this->name_ << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap &copy) : ClapTrap(copy.name_), FragTrap(copy.name_), ScavTrap(copy.name_){
	*this = copy;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs){
	this->name_ = rhs.name_;
	this->hitPoint_ = rhs.hitPoint_;
	this->energyPoint_ = rhs.energyPoint_;
	this->attackDamage_ = rhs.attackDamage_;
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << this->name_ << " destructor called" << std::endl;
}

void	DiamondTrap::whoAmI( void ){
	std::cout << "I am a DiamondTrap. My name is: " << this->name_ << ", and my ClapTrap name is: " << ClapTrap::name_ << std::endl;
}


// void	DiamondTrap::attack(const std::string &target)
// {
// 	ScavTrap::attack(target);
// }
