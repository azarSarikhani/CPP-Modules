/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:23:27 by asarikha          #+#    #+#             */
/*   Updated: 2023/08/14 09:36:01 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;
	
	std::cout << "string address: " << &str << std::endl;
	std::cout << "string pointer's (stringPTR) address: " << stringPTR << std::endl;
	std::cout << "string refrance's (stringREF) address: " << &stringREF << std::endl;
	std::cout << "string's value: " << str << std::endl;
	std::cout << "string pointer's value: " << *stringPTR << std::endl;
	std::cout << "string refrance's value: " << stringREF << std::endl;
	return (0);
}