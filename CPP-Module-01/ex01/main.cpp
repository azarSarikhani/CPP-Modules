/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:03:21 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/11 17:16:52 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 10

Zombie* zombieHorde(int n, std::string name);

int	main(void)
{
	
	Zombie *zombiez = zombieHorde(N, "zizi");
	for(size_t  i = 0; i < N; i++ )
	{
		zombiez[i].announce();
	}
	delete[] zombiez;
	
	return (0);
}