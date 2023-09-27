/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:03:21 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/25 10:47:45 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	std::string	name;
	std::cout << GRAY_BG << "This Zomibie is going to be allocated on the stack." << RESET << std::endl;
	std::cout << GRAY_BG << "Name the zombie: " << RESET << std::flush;
	std::cin >> name;
	Zombie stackZombie(name);
	stackZombie.announce();
	std::cout << YELLOW_BG << "This Zomibie is going to be allocated on the heap." << RESET << std::endl;
	std::cout << YELLOW_BG << "Name the zombie: " << RESET << std::flush;
	std::cin >> name;
	Zombie *heapZombie = newZombie(name);
	heapZombie->announce();
	delete(heapZombie);
	std::cout << WHITE_BG << "RandomChump is allocating a zombie on the stack." << RESET << std::endl;
	std::cout << WHITE_BG << "Name the zombie: " << RESET << std::flush;
	std::cin >> name;
	randomChump(name);
	return (0);
}