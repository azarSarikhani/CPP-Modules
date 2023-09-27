/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:34:40 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/25 10:49:02 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){
}

HumanA::~HumanA(){
}

void	HumanA::attack(void){
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon){
	this->_weapon = weapon;
}