/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:34:48 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/14 11:30:15 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType) : _clubType(weaponType){
}

Weapon::~Weapon(){
}

const	std::string& Weapon::getType(void) const{
	return (this->_clubType);
}

void	Weapon::setType(std::string newClub){
	this->_clubType = newClub;
}