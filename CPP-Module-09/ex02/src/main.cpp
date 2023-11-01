/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:57:35 by asarikha          #+#    #+#             */
/*   Updated: 2023/10/31 15:50:24 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned int ft_stou(const std::string& str)
{
    if (str.length() > 10)
        throw (std::invalid_argument ( "input should be whithin the range of unsigned int" ));
    unsigned int num;
    std::stringstream ss(str);

    ss >> num;
    
    unsigned int unsignedInteger = num;
    std::stringstream checkSS;
	checkSS << unsignedInteger;
    if ( checkSS.str().compare ( str ) != 0 )
        throw (std::invalid_argument ( "input should be whithin the range of unsigned int" ) );
    return num;
}

int main ( int argc, char* argv[] ){
	
	if (argc == 1)
	    return 0;
    PmergeMe pmm;

    try {
        for (int i = 1; i < argc; i += 1)
            if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
			    throw (std::invalid_argument ( "input should be positive integer sequence only" ));

        std::vector<unsigned int>temp;
        for (int i = 1; i < argc; i += 1){
            temp.push_back(ft_stou(argv[i]));
        }

        // std::vector<unsigned int>::iterator itr;
        // std::vector<unsigned int>::iterator itr2;
        // for (itr = temp.begin(); itr != temp.end(); itr++)
        // {
        //     for (itr2 = itr + 1; itr2 != temp.end(); itr2++){
        //         if (*itr2 == *itr)
		// 	        throw (std::invalid_argument ( "Duplicates not allowed" ));
        //     }
        // }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
	pmm.sortVec(argc, argv);
    // merge_insert_vec(int_vec, 0, int_vec.size() - 1); // -1 because last element is unpaired
    std::cout << std::endl;
    pmm.sortList(argc, argv);
    // merge_insert_list(int_list, 0, int_list.size() - 1); // -1 because last element is unpaired in insertion sort
	return 0;
}