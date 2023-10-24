/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:17:54 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/24 16:14:58 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
#include <fstream>

int	replace(std::string toFind, std::string toReplace, std::string infile, std::string str)
{
	std::ofstream outfile;
	int				pos;

	if (!toFind[0])
	{
		std::cerr << "invalid input\n";
		return (EXIT_FAILURE);
	}
	outfile.open(((infile) + ".replace").c_str());
	if (outfile.fail()){
		std::cerr << "Replace file can not be opened!" << std::endl;
		return (EXIT_FAILURE);
	}
	for (int i = 0; i < (int)str.size(); i++)
	{
		pos = str.find(toFind, i);
		if (pos != -1 && pos == i)
		{
			outfile << toReplace;
			i += std::string(toFind).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}


int	main(int argc, char **argv){
	std::ifstream	infile;
	std::string		string;
	std::string		temp;
	
	if (argc != 4)
	{
		std::cerr << "usage: ./replace \"file\" \"old_word\" \"new_word\"" << std::endl;
		return (EXIT_FAILURE);
	}
	infile.open(argv[1], std::ios::out);
	if(infile.fail() == true) {
        std::cerr << "Error: " << argv[1] << ":" << " no such file or directory" << std::endl;
		return (EXIT_FAILURE);
    }
	while (getline(infile, temp)) {  
			string += temp;
			if (infile.eof())
				break;
			string += "\n";
        }
	//std::cout << string << "\n";
	infile.close();
	
	return (replace(argv[2], argv[3], argv[1], string));
}