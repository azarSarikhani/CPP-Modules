/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:40:35 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/29 15:22:03 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap Bart("Simpson");
	FragTrap Nelson(Bart);
	Bart.attack( "Nelson" );
	Bart.takeDamage(10);
	Bart.beRepaired(20);
	Bart.highFive();
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