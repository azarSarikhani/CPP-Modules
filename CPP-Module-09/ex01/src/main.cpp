/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:01:05 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/20 11:13:29 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char* argv[]){
	if (argc != 2)
		return (std::cout << "RPN must recieve arguments." << std::endl, 0);
	RPN rpn;
	std::string input = argv[1];
	try
	{
		rpn.validateInput(input);
		rpn.calculateResult(input);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}