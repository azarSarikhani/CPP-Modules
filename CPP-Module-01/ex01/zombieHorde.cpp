/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:38:50 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/11 17:16:14 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name){
	Zombie *zombi = new Zombie[n];
	for (int i = 0; i < n; i++){
		zombi[i].setName(name);
	}
	return zombi;
}