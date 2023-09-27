/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:26:28 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/25 10:49:10 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
	
}

Zombie::~Zombie(){
	std::cout << GREEN << "Zombie " << this->_name << "  has been destroyed." << RESET << std::endl;
}

void	Zombie::announce(void){
	std::cout << GREEN_BG << this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}