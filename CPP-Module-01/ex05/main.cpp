/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarsarikhani <azarsarikhani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:17:54 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/16 13:22:00 by azarsarikha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string input;
    Harl        harl;

    do
    {
        std::cout << "Enter a level: ";
        std::cin >> input;
        harl.complain(input);
    } while (input.compare("exit") && input.compare("EXIT"));

    return (EXIT_SUCCESS);

}
