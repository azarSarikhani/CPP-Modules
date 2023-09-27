/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:29:50 by asarikha          #+#    #+#             */
/*   Updated: 2023/09/25 10:46:53 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char* argv[])
{
	char ch;
	if (argc == 1)
		std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < std::strlen(argv[i]); j++)
		{
			ch = std::toupper(argv[i][j]);
			std::cout << ch;
		}
	}
	std::cout << std::endl;
	return 0;
}
