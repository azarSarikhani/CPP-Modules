/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:40:35 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/01 17:22:02 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap Bart("Simpson");
	DiamondTrap Nelson("Nelson");
	Nelson = Bart;
	DiamondTrap Lisa("Lisa Simpson");
	Bart.attack( "Nelson" );
	Bart.takeDamage(10);
	Bart.beRepaired(20);
	Bart.whoAmI();
	Lisa.whoAmI();
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