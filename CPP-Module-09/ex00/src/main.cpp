/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:33:19 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/19 11:10:09 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
using std::cerr;

int main(int argc, char**argv){
	if (argc != 2)
		return (std::cout << "BitcoinExchange must recieve a input file as argument" << std::endl, 0);
	BitcoinExchange bitcoinExchange;

	(void)argv;

	try {
		bitcoinExchange.parseData();
		bitcoinExchange.parseInput(argv[1]);
	}
	catch (std::exception &e) {
		cerr << e.what() << std::endl; //std::cout ?
		return (1);
	}
	return 0;
}