/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:40:35 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/29 15:00:45 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Bart("Simpson");
	ScavTrap Nelson(Bart);
	Bart.attack( "Nelson" );
	Bart.takeDamage(10);
	Bart.beRepaired(20);
	Bart.gaurdGate();
	Nelson.attack( "Nelson" );
	Nelson.takeDamage(10);
	Nelson.takeDamage(10);
	Nelson.takeDamage(10);
	Nelson.takeDamage(10);
	Nelson.takeDamage(10);
	Nelson.takeDamage(10);
	Nelson.takeDamage(10);
	Nelson.takeDamage(10);
	Nelson.takeDamage(10);
	Nelson.takeDamage(10);
	Nelson.takeDamage(10);
	Nelson.takeDamage(10);
	return (0);
}