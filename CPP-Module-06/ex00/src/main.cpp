/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:43:45 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/18 13:42:07 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv){
	if (argc != 2 || argv[1][0] == 0){
		std::cout << "Usage: ./Converter <data that you want to convert>" << std::endl;
		return (1);
	}
	std::string arg(argv[1]);
	ScalarConverter::convert(arg);
}