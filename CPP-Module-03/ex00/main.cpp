/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:40:35 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/29 10:29:13 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("attacker");
	claptrap.attack("blow reciever");
	claptrap.takeDamage(2);
	claptrap.attack("blow reciever");
	claptrap.takeDamage(2);
	claptrap.attack("blow reciever");
	claptrap.takeDamage(2);
	claptrap.takeDamage(2);
	claptrap.takeDamage(2);
	claptrap.beRepaired(12);
	claptrap.takeDamage(2);
	claptrap.beRepaired(52);
	claptrap.takeDamage(2);
	return (0);
}