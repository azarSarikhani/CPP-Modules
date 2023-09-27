/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azarsarikhani <azarsarikhani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:17:54 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/16 17:04:25 by azarsarikha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char** argv)
{
	std::string input;
    Harl        harl;

    if(argc != 2){
        return (std::cout << "Usage: ./harlFilter \"level\"\n", EXIT_FAILURE);
    }
    input = argv[1];
    harl.complain(input);

    return (EXIT_SUCCESS);

}
