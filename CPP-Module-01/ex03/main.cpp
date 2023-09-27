/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:33:30 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/14 12:44:31 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA a("Human A", club);
		a.attack();
		club.setType("some other type of club");
		a.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB b("Human B");
		b.setWeapon(club);
		b.attack();
		club.setType("some other type of club");
		b.attack();
	}
	return 0;
}